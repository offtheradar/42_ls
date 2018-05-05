/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 18:55:53 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

void	visit_dir(t_file_info *root, char *file_name)
{
	t_file_info *tmp;

	tmp = root;
	while (tmp)
	{
		if (tmp->f_type == 'd' && NOT_CURR_DIR(tmp) &&
				ft_strcmp(file_name, tmp->name))
			tmp->to_visit = 1;
		tmp = tmp->next;
	}
}

void	ft_ls(t_options *opt, char *file_name)
{
	t_file_info	*root;
	t_file_info *start;
	char		*full_path;
	char		*tmp;

	root = get_file_info(file_name);
	start = root;
	order_lst(&(root->next), opt);
	print_lst_info(root, opt);
	if (opt->R)
	{
		visit_dir(root, file_name);
		while (root)
		{
			if (root->to_visit)
			{
				full_path = ft_strdup(file_name);
				tmp = ft_strjoin(full_path, "/");
				full_path = ft_strjoin(tmp, root->name);
				free(tmp);
				ft_ls(opt, full_path);
				free(full_path);
			}
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
