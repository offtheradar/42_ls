/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:15:11 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 12:59:16 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <time.h>
#include <stdio.h>

void	print_permissions(t_file_info *root)
{
	printf("%c%c%c%c%c%c%c%c%c%c ", root->f_type, root->o_read, root->o_write,
			root->o_exec, root->g_read, root->g_write, root->g_exec,
			root->a_read, root->a_write, root->a_exec);
}

void	print_lst_info(t_file_info *root, t_options *opt)
{
	int i;
	t_file_info *first;

	i = 3;
	first = root;
	while (root && opt)
	{
		if (root == first)
			printf("%s:\n", root->name);
		else if (ft_strcmp(root->name, ".") != 0 && ft_strcmp(root->name, "..") != 0)
		{
			print_permissions(root);
			printf("%d ", root->num_links);
			printf("%s ", root->owner_name);
			printf("%s ", root->group_name);
			printf("%d ", root->size);
			i = 3;
			while (++i < 16)
				printf("%c", root->m_time[i]);
			printf(" ");
			printf("%s\n", root->name);
		}
		root = root->next;
	}
	printf("\n");
}
