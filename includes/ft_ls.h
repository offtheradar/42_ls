/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/02 21:19:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>

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
	int		num_links;
	char	*owner_name;
	char	*group_name;
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

t_options			*init_options(void);

void				set_options(char *options, t_options *opt);

int					get_options(int argc, char **argv, t_options *opt);

t_file_info			*get_file_info(char *str);
#endif
