/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/03 11:40:42 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

typedef struct		s_options
{
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}					t_options;

typedef	struct		s_file_info
{
	char				*name;
	//int		is_hidden;
	char	f_type;
	int		m_time;
	int		size;
	int		num_links;
	char	*owner_name;
	char	*group_name;
	char	*path_name;
	char	o_read;
	char	o_write;
	char	o_exec;
	char	g_read;
	char	g_write;
	char	g_exec;
	char	a_read;
	char	a_write;
	char	a_exec;
	struct s_file_info *next;
}					t_file_info;

t_file_info			*init_file_info(void);

void				set_file_type(t_file_info *root, struct stat *buff);

void				set_file_permissions(t_file_info *root, struct stat *buff);

t_options			*init_options(void);

void				set_options(char *options, t_options *opt);

int					get_options(int argc, char **argv, t_options *opt);

t_file_info			*get_file_info(char *str);

void				print_lst_info(t_file_info *root, t_options *opt);

void				free_f_info_lst(t_file_info *root);

void				ft_ls(t_options *opt, char *file_name);
#endif
