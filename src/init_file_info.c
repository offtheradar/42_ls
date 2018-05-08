/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:57:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 20:59:13 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

void			init_file_permissions(t_file_info **root)
{
	(*root)->o_read = 0;
	(*root)->o_write = 0;
	(*root)->o_exec = 0;
	(*root)->g_read = 0;
	(*root)->g_write = 0;
	(*root)->g_exec = 0;
	(*root)->a_read = 0;
	(*root)->a_write = 0;
	(*root)->a_exec = 0;
}

t_file_info		*init_file_info(void)
{
	t_file_info *root;

	root = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	root->f_type = 0;
	root->is_hidden = 0;
	root->m_time = 0;
	root->num_links = 0;
	root->size = 0;
	root->num_links = 0;
	root->owner_name = 0;
	root->group_name = 0;
	root->path_name = 0;
	root->size = 0;
	root->to_visit = 0;
	root->blocks = 0;
	init_file_permissions(&root);
	root->next = NULL;
	return (root);
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
