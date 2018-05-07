/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:15:11 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 12:26:11 by ysibous          ###   ########.fr       */
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

void	print_time(t_file_info *root)
{
	int i;

	i = 3;
	while (++i < 16)
		printf("%c", root->m_time[i]);
	printf(" ");
}

int		add_blocks(t_file_info *root, t_options *opt)
{
	t_file_info		*tmp;
	int				num_blocks;

	tmp = root;
	tmp = tmp->next;
	num_blocks = 0;
	while (tmp)
	{
		if (!opt->a && tmp->name[0] == '.')
			;
		else
			num_blocks += tmp->blocks;
		tmp = tmp->next;
	}
	return (num_blocks);
}

void	print_lst_info(t_file_info *root, t_options *opt)
{
	t_file_info *first;

	first = root;
	while (root)
	{
		if (root == first)
		{
			printf("%s:\n", root->name);
			if (opt->l)
				printf("total %d\n", add_blocks(root, opt));
		}
		else
		{
			if (opt->l && root != first)
			{
				print_permissions(root);
				printf("%d %s %s %d ", root->num_links, root->owner_name,
										root->group_name, root->size);
				print_time(root);
			}
			if (root != first)
				printf("%s\n", root->name);
		}
		root = root->next;
	}
	printf("\n");
}
