/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/28 11:25:36 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int  i;
	//DIR *d;
	//struct dirent *dir;
	t_options *opt;
	
	opt = (t_options *)ft_memalloc(sizeof(t_options));
	init_options(opt);
	i = 1;
/*
	if (argc == 1)
		d = opendir(".");
	else
		d = opendir(argv[1]);
*/
	while (i < argc && argv[i][0] == '-')
	{
		get_options(argv[i], opt);
		i++;
	}
/*
	if (d)
	{
		while ((dir = readdir(d)))
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
*/
	printf("l is %d\n", opt->l);
	printf("R is %d\n", opt->R);
	printf("a is %d\n", opt->a);
	printf("r is %d\n", opt->r);
	printf("t is %d\n", opt->t);
	return (0);
}
