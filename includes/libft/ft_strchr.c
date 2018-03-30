/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:53:27 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 20:50:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_new;

	s_new = (char*)s;
	while (*s_new)
	{
		if (*s_new == (char)c)
			return (s_new);
		s_new++;
	}
	if (*s_new == (char)c)
		return (s_new);
	return (NULL);
}
