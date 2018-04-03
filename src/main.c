/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/02 21:23:55 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

t_file_info		*init_file_info(void)
{
	t_file_info *root;

	root = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	root->f_type = 0;
	root->m_time = 0;
	root->num_links = 0;
	root->owner_name = 0;
	root->o_read = 0;
	root->o_write = 0;
	root->o_exec = 0;
	root->g_read = 0;
	root->g_write = 0;
	root->g_exec = 0;
	root->a_read = 0;
	root->a_write = 0;
	root->a_exec = 0;
	root->next = NULL;
	return (root);
}

void			set_file_type(t_file_info *new, struct stat *buff)
{
	if (S_ISDIR(buff->st_mode))
		(new)->f_type = 'd';
	if (S_ISREG(buff->st_mode))
		(new)->f_type = '-';
	if (S_ISFIFO(buff->st_mode))
		(new)->f_type = 'p';
	if (S_ISCHR(buff->st_mode))
		(new)->f_type = 'c';
	if (S_ISBLK(buff->st_mode))
		(new)->f_type = 'b';
	if (S_ISLNK(buff->st_mode))
		(new)->f_type = 'l';
	if (S_ISSOCK(buff->st_mode))
		(new)->f_type = 's';
}

void			set_file_permissions(t_file_info *root, struct stat *buff)
{
	root->o_read = (buff->st_mode & S_IRUSR) ? 'r' : '-';
	root->o_write = (buff->st_mode & S_IWUSR) ? 'w' : '-';
	root->o_exec = (buff->st_mode & S_IXUSR) ? 'x' : '-';
	root->g_read = (buff->st_mode & S_IRGRP) ? 'r' : '-';
	root->g_write = (buff->st_mode & S_IWGRP) ? 'w' : '-';
	root->g_exec = (buff->st_mode & S_IXGRP) ? 'x' : '-';
	root->a_read = (buff->st_mode & S_IROTH) ? 'r' : '-';
	root->a_write = (buff->st_mode & S_IWOTH) ? 'w' : '-';
	root->a_exec = (buff->st_mode & S_IXOTH) ? 'x' : '-';
}

t_file_info		*get_file_info(char *str)
{
	struct stat *buff;
	struct passwd *pw;
	struct group *grp;
	t_file_info *new;
	t_file_info *root;
	t_file_info *start;
	DIR			*d = NULL;
	struct dirent	*dir = NULL;

	root = init_file_info();
	start = root;
	buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	dir = (struct dirent *)ft_memalloc(sizeof(struct dirent));
	root->name = ft_strnew(ft_strlen(str));
	lstat(str, buff);
	root->name = str;
	root->m_time = buff->st_mtime;
	grp = getgrgid(buff->st_gid);
	root->group_name = grp->gr_name;
	pw = (getpwuid(buff->st_uid));
	root->owner_name = pw->pw_name;
	set_file_type(root, buff);
	if (root->f_type == 'd')
	{
		d = opendir(str);
		while ((dir = readdir(d)))
		{
			new = init_file_info();
			new->name = ft_strnew(ft_strlen(dir->d_name));
			new->name = dir->d_name;
			lstat(new->name, buff);
			set_file_type(new, buff);
			new->m_time = buff->st_mtime;
			pw = (getpwuid(buff->st_uid));
			new->owner_name = pw->pw_name;
			grp = getgrgid(buff->st_gid);
			new->group_name = grp->gr_name;
			root->next = new;
			root = root->next;
		}
		root->next = NULL;
		closedir(d);
	}
	return (start);
}
/*
void	order_f_info_lst(t_file_info **root, t_options *opt)
{
	return ;
}
*/
void	print_lst_info(t_file_info *root, t_options *opt)
{
	while (root)
	{
		if (!opt->a && root->name[0] != '.')
		{
			printf("%s ", root->group_name);
			printf("%s ", root->owner_name);
			printf("%d\n", root->m_time);
		}
		root = root->next;
	}
}

void	free_f_info_lst(t_file_info **root)
{
	t_file_info *tmp;

	while(*root)
	{
		tmp = *root;
		*root = (*root)->next;
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	int  i;
	t_file_info *root;
	t_options *opt;
	opt = init_options();
	//i = get_options(argc, argv, opt);
	i = 1;
	while (i < argc)
	{
		root = get_file_info(argv[i]);
		print_lst_info(root, opt);
/*
		if (opt->t || opt->r)
			order_f_info_lst(&root,opt);
		if (opt->R)
	
		{
			while (root)
			{
				if (root->is_dir)
					main()
			}
		}*/
		free_f_info_lst(&root);
		i++;
	}
	return (0);
}
