/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:15:11 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/03 14:41:06 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

void	print_lst_info(t_file_info *root, t_options *opt)
{
	opt = 0;
	while (root)
	{
	/*	if (!opt->a && root->name[0] != '.')
		{*/
			//printf("%d ", root->num_links);
			//printf("%s ", root->group_name);
			//printf("%s ", root->owner_name);
			//printf("%d ", root->size);
			//printf("%d ", root->m_time);
			printf("%s\n", root->name);
		//}
		root = root->next;
	}
}
