/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:10:14 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/03 19:35:48 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_new;
	char	*s2_new;
	int		len_s1_s2;
	char	*join_str;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	s1_new = (char*)s1;
	s2_new = (char*)s2;
	len_s1_s2 = ft_strlen(s1_new) + ft_strlen(s2_new);
	if (!(join_str = ft_strnew(len_s1_s2)))
		return (NULL);
	start = join_str;
	while (*s1_new)
		*(join_str++) = *(s1_new++);
	while (*s2_new)
		*(join_str++) = *(s2_new++);
	*join_str = '\0';
	return (start);
}
