/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/28 15:42:35 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# include "libft/libft.h"
# include <dirent.h>

typedef struct		s_options
{
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}					t_options;

void				init_options(t_options *opt);

void				set_options(char *options, t_options *opt);

int					get_options(int argc, char **argv, t_options *opt);
#endif
