/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/03 16:49:27 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

void	ft_ls(t_options *opt, char *file_name)
{
	t_file_info	*root;
	t_file_info *start;

	root = get_file_info(file_name);
	start = root;
	//order_f_info_lst(&root, opt);
	print_lst_info(root, opt);
	if (opt->R)
	{
		while (root)
		{
			if (root->f_type == 'd' && !ft_strcmp(".", root->name) &&
						!ft_strcmp("..", root->name))
				ft_ls(opt, root->name);
			root = root->next;
		}
	}
	free_f_info_lst(start);
}

int		main(int argc, char **argv)
{
	int			i;
	t_options	*opt;

	opt = init_options();
	i = get_options(argc, argv, opt);
	if (i == argc)
		ft_ls(opt, ".");
	else
		while (i < argc)
		{
			ft_ls(opt, argv[i]);
			i++;
		}
	free(opt);
	return (0);
}
