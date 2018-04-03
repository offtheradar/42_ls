/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/03 12:21:11 by ysibous          ###   ########.fr       */
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
	print_lst_info(root, opt);
	if (opt->R)
	{
		while (root)
		{
			if (root->f_type == 'd')
				ft_ls(opt, root->name);
			root = root->next;
		}
	}
	free_f_info_lst(&start);
}

int		main(int argc, char **argv)
{
	int  i;
	t_options *opt;
	opt = init_options();
	i = 1;
	while (i < argc)
	{
		ft_ls(opt, argv[i]);
		i++;
	}
	while (1)
	{;}
	return (0);
}
