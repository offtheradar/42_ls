/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaison_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:53:44 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 19:08:17 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			f_name_cmp(t_file_info *a, t_file_info *b)
{
	return (ft_strcmp(a->name, b->name));
}

int			f_name_cmp_r(t_file_info *a, t_file_info *b)
{
	return (ft_strcmp(b->name, a->name));
}

int			f_time_cmp(t_file_info *a, t_file_info *b)
{
	if (a->m_time_num > b->m_time_num)
		return (1);
	else if (a->m_time_num == b->m_time_num)
		return (f_name_cmp(a, b));
	else
		return (0);
}

int			f_time_cmp_r(t_file_info *a, t_file_info *b)
{
	if (a->m_time_num < b->m_time_num)
		return (1);
	else if (a->m_time_num == b->m_time_num)
		return (f_name_cmp_r(a, b));
    else
        return (0);
}
