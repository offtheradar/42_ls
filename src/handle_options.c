/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:17:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 19:10:42 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_options	*init_options(void)
{
	t_options *opt;

	opt = (t_options *)ft_memalloc(sizeof(t_options));
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	return (opt);
}

void		set_options(char *options, t_options *opt)
{
	if (ft_strchr(options, 'l'))
		opt->l = 1;
	if (ft_strchr(options, 'R'))
		opt->R = 1;
	if (ft_strchr(options, 'a'))
		opt->a = 1;
	if (ft_strchr(options, 'r'))
		opt->r = 1;
	if (ft_strchr(options, 't'))
		opt->t = 1;
}

int			get_options(int argc, char **argv, t_options *opt)
{
	int i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		set_options(argv[i], opt);
		i++;
	}
	return (i);
}
