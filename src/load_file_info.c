/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:12:51 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 17:34:10 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

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
	root->path_name = 0;
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
	root->to_visit = 0;
	root->m_time_num = 0;
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
	struct stat		*buff;
	struct passwd	*pw;
	struct group	*grp;
	t_file_info		*new;
	t_file_info		*root;
	t_file_info		*start;
	DIR				*d;
	struct dirent	*dir;
	char			*path;
	char			*tmp;

	d = NULL;
	dir = NULL;
	root = init_file_info();
	start = root;
	buff = ft_memalloc(sizeof(struct stat));
	root->name = ft_strdup(str);
	lstat(str, buff);
	root->m_time_num = buff->st_mtime;
	root->m_time = ctime(&(buff->st_mtime));
	grp = getgrgid(buff->st_gid);
	root->group_name = ft_strdup(grp->gr_name);
	pw = (getpwuid(buff->st_uid));
	root->owner_name = ft_strdup(pw->pw_name);
	root->size = buff->st_size;
	root->num_links = buff->st_nlink;
	set_file_type(root, buff);
	set_file_permissions(root, buff);
	if (root->f_type == 'd')
	{
		d = opendir(str);
		tmp = ft_strdup(root->name);
		path = ft_strjoin(tmp, "/");
		free(tmp);
		while ((dir = readdir(d)))
		{
			free(buff);
			buff = ft_memalloc(sizeof(struct stat));
			new = init_file_info();
			new->name = ft_strdup(dir->d_name);
			tmp = ft_strjoin(path, new->name);
			lstat(tmp, buff);
			free(tmp);
			set_file_type(new, buff);
			set_file_permissions(new, buff);
			new->m_time_num = buff->st_mtime;
			new->m_time = ctime(&(buff->st_mtime));
			if ((pw = (getpwuid(buff->st_uid))) != NULL)
				new->owner_name = ft_strdup((char *)(pw->pw_name));
			if ((grp = getgrgid(buff->st_gid)) != NULL)
				new->group_name = ft_strdup(grp->gr_name);
			new->size = buff->st_size;
			new->num_links = buff->st_nlink;
			root->next = new;
			root = root->next;
		}
		free(path);
		free(dir);
		free(buff);
		root->next = NULL;
		closedir(d);
	}
	else
	{
		free(buff);
		root->next = NULL;
	}
	return (start);
}

void			free_f_info_lst(t_file_info *root)
{
	t_file_info *tmp;

	while (root)
	{
		tmp = root;
		if ((root)->owner_name)
			free((root)->owner_name);
		if ((root)->group_name)
			free((root)->group_name);
		if ((root)->name)
			free((root)->name);
		if ((root)->path_name)
			free(root->path_name);
		root = (root)->next;
		free(tmp);
	}
}
