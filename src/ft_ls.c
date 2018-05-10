/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:13:30 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/08 16:33:18 by ysibous          ###   ########.fr       */
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

void	handle_recursion(t_options *opt, t_file_info **root, char *file_name)
{
	char		*full_path;
	char		*tmp;

	visit_dir(*root, file_name);
	while (*root)
	{
		if ((*root)->to_visit)
		{
			if (!opt->a && (*root)->name[0] == '.')
				;
			else
			{
				full_path = ft_strdup(file_name);
				tmp = ft_strjoin(full_path, "/");
				free(full_path);
				full_path = ft_strjoin(tmp, (*root)->name);
				free(tmp);
				ft_ls(opt, full_path);
				free(full_path);
			}
		}
		*root = (*root)->next;
	}
}

void	ft_ls(t_options *opt, char *file_name)
{
	t_file_info	*root;
	t_file_info *start;
	static int	is_first;

	root = get_file_info(file_name);
	if (!root->f_type)
	{
		ft_putstr("ft_ls: No such file or directory\n\n");
		return ;
	}
	start = root;
	order_lst(&(root->next), opt);
	print_lst_info(root, opt, is_first);
	is_first += 1;
	if (opt->ur)
		handle_recursion(opt, &root, file_name);
	free_f_info_lst(start);
}
