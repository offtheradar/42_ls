/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 21:04:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# define NOT_CURR_DIR(x) (ft_strcmp(x->name, ".") && ft_strcmp(x->name, ".."))

typedef struct		s_options
{
	int		l;
	int		ur;
	int		a;
	int		r;
	int		t;
}					t_options;

typedef	struct			s_file_info
{
	char				*name;
	char				f_type;
	char				*m_time;
	int					is_hidden;
	struct timespec		m_time_num;
	int					blocks;
	int					size;
	int					num_links;
	int					to_visit;
	char				*owner_name;
	char				*group_name;
	char				*path_name;
	char				o_read;
	char				o_write;
	char				o_exec;
	char				g_read;
	char				g_write;
	char				g_exec;
	char				a_read;
	char				a_write;
	char				a_exec;
	struct s_file_info	*next;
}						t_file_info;

void				ft_ls(t_options *opt, char *file_name);

/*
******************************* ls Helpers *************************************
*/

void				visit_dir(t_file_info *root, char *file_name);

char				*create_path(char *file_name, t_file_info *root);

/*
******************************* Options ****************************************
*/

t_options			*init_options(void);

void				set_options(char *options, t_options *opt);

int					get_options(int argc, char **argv, t_options *opt);

/*
******************************* List Constructors ******************************
*/

t_file_info			*get_file_info(char *str);

t_file_info			*init_file_info(void);

void				set_file_type(t_file_info *root, struct stat *buff);

void				set_file_permissions(t_file_info *root, struct stat *buff);

t_file_info			*init_file_info(void);

void				free_f_info_lst(t_file_info *root);

/*
******************************* Print ******************************************
*/

void				print_lst_info(t_file_info *root, t_options *opt,
										int is_first);

void				print_time(t_file_info *root);

void				print_permissions(t_file_info *root);

/*
******************************* Sorting ****************************************
*/

int					f_name_cmp(t_file_info *a, t_file_info *b);

int					f_name_cmp_r(t_file_info *a, t_file_info *b);

int					f_time_cmp(t_file_info *a, t_file_info *b);

int					f_time_cmp_r(t_file_info *a, t_file_info *b);

void				split(t_file_info *source, t_file_info **front,
							t_file_info **back);

t_file_info			*merge(t_file_info *a, t_file_info *b,
						int (*order)(t_file_info *a, t_file_info *b));

void				merge_sort(t_file_info **root,
						int (*order)(t_file_info *a, t_file_info *b));

void				order_lst(t_file_info **root, t_options *opt);

#endif
