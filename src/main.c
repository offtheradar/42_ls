/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/30 15:26:56 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

t_file_info		*init_file_info(void)
{
	t_file_info *root;

	root = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	root->is_dir = 0;
//	root->parent = root;
	root->next = NULL;
//	root->files = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	return (root);
}

t_file_info		*get_file_info(char *str)
{
	struct stat *buff;
	t_file_info *new;
	t_file_info *root;
	t_file_info *start;
	DIR			*d = NULL;
	struct dirent	*dir = NULL;

	root = init_file_info();
	start = root;
	buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	dir = (struct dirent *)ft_memalloc(sizeof(struct dirent));
	root->name = ft_strnew(ft_strlen(str));
	lstat(str, buff);
	root->name = str;
	if (S_ISDIR(buff->st_mode))
	{
		root->is_dir = 1;
		d = opendir(str);
		while ((dir = readdir(d)))
		{
			new = init_file_info();
			new->name = ft_strnew(ft_strlen(dir->d_name));
			new->name = dir->d_name;
			lstat(new->name, buff);
			if (S_ISDIR(buff->st_mode))
				new->is_dir = 1;
			root->next = new;
			root = root->next;
		}
		root->next = NULL;
		closedir(d);
	}
	return (start);
}
/*
void	order_f_info_lst(t_file_info **root, t_options *opt)
{
	return ;
}
*/
void	print_lst_info(t_file_info *root)
{
	while (root)
	{
		printf("%s\n", root->name);
		root = root->next;
	}
}

void	free_f_info_lst(t_file_info **root)
{
	t_file_info *tmp;

	while(*root)
	{
		tmp = *root;
		*root = (*root)->next;
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	int  i;
	t_file_info *root;
	t_options *opt;
	opt = init_options();
	//i = get_options(argc, argv, opt);
	i = 1;
	while (i < argc)
	{
		root = get_file_info(argv[i]);
		print_lst_info(root);
/*
		if (opt->t || opt->r)
			order_f_info_lst(&root,opt);
		if (opt->R)
	
		{
			while (root)
			{
				if (root->is_dir)
					main()
			}
		}*/
		free_f_info_lst(&root);
		i++;
	}
	printf("l is %d\n", opt->l);
	printf("R is %d\n", opt->R);
	printf("a is %d\n", opt->a);
	printf("r is %d\n", opt->r);
	printf("t is %d\n", opt->t);
	return (0);
}
