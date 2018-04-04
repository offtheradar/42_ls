/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:12:51 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/03 12:14:21 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file_info		*init_file_info(void)
{
	t_file_info *root;

	root = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	root->f_type = 0;
	root->m_time = 0;
	root->num_links = 0;
	root->size = 0;
	root->num_links = 0;
	root->owner_name = 0;
	root->group_name = 0;
	root->o_read = 0;
	root->o_write = 0;
	root->o_exec = 0;
	root->g_read = 0;
	root->g_write = 0;
	root->g_exec = 0;
	root->a_read = 0;
	root->a_write = 0;
	root->a_exec = 0;
	root->size = 0;
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
	buff = malloc(sizeof(struct stat));
	dir = malloc(sizeof(struct dirent));
	root->name = ft_strnew(ft_strlen(str));
	lstat(str, buff);
	root->name = str;
	root->m_time = buff->st_mtime;
	grp = getgrgid(buff->st_gid);
	root->group_name = grp->gr_name;
	pw = (getpwuid(buff->st_uid));
	root->owner_name = pw->pw_name;
	root->size = buff->st_size;
	root->num_links = buff->st_nlink;
	set_file_type(root, buff);
	if (root->f_type == 'd')
	{
		d = opendir(str);
		while ((dir = readdir(d)))
		{
			free(buff);
			buff = malloc(sizeof(struct stat));
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
			new->size = buff->st_size;
			new->num_links = buff->st_nlink;
			root->next = new;
			root = root->next;
		}
		free(buff);
		root->next = NULL;
		closedir(d);
	}
	return (start);
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
