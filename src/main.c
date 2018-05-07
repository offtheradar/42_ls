/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/05 17:09:41 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

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
	while (1){};
	return (0);
}
