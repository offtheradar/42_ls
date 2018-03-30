/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:57:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:05:23 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*s_new;

	s_new = (char*)s;
	ptr = 0;
	while (*s_new)
	{
		if (*s_new == c)
			ptr = s_new;
		s_new++;
	}
	if (*s_new == c)
		return (s_new);
	return (ptr);
}
