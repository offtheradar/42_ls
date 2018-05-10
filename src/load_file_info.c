/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:12:51 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/09 19:23:09 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

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

void			set_root_info(t_file_info *root, struct stat buff)
{
	struct passwd	*pw;
	struct group	*grp;

	root->m_time_num = buff.st_mtimespec;
	root->m_time = ft_strdup(ctime(&(buff.st_mtimespec.tv_sec)));
	root->blocks = buff.st_blocks;
	grp = getgrgid(buff.st_gid);
	root->group_name = ft_strdup(grp->gr_name);
	pw = (getpwuid(buff.st_uid));
	root->owner_name = ft_strdup(pw->pw_name);
	root->size = buff.st_size;
	root->num_links = buff.st_nlink;
	set_file_type(root, &buff);
	set_file_permissions(root, &buff);
}

void			set_files_in_dir(t_file_info **root, char *str,
									struct stat buff)
{
	DIR				*d;
	struct dirent	*dir;
	char			*path;
	char			*tmp;
	t_file_info		*new;

	d = opendir(str);
	tmp = ft_strdup((*root)->name);
	path = ft_strjoin(tmp, "/");
	free(tmp);
	while ((dir = readdir(d)))
	{
		new = init_file_info();
		if ((new->name = ft_strdup(dir->d_name)) && new->name[0] == '.')
			new->is_hidden = 1;
		tmp = ft_strjoin(path, new->name);
		lstat(tmp, &buff);
		free(tmp);
		set_root_info(new, buff);
		(*root)->next = new;
		(*root) = (*root)->next;
	}
	free(path);
	free(dir);
	closedir(d);
}

t_file_info		*get_file_info(char *str)
{
	struct stat		buff;
	t_file_info		*root;
	t_file_info		*start;

	root = init_file_info();
	start = root;
	root->name = ft_strdup(str);
	if (root->name[0] == '.')
		root->is_hidden = 1;
	lstat(str, &buff);
	set_root_info(root, buff);
	if (root->f_type == 'd')
		set_files_in_dir(&root, str, buff);
	root->next = NULL;
	return (start);
}
