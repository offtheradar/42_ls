/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:01:28 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 20:30:42 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cpy;
	size_t	i;

	i = 0;
	s_cpy = (char *)s;
	while (i < n)
	{
		if (s_cpy[i] == (char)c)
			return ((void *)(&s_cpy[i]));
		i++;
	}
	return (NULL);
}
