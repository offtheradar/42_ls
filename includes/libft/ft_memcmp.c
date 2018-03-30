/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:04:42 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 22:13:55 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	size_t			i;

	i = 0;
	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	while (i < n && s1_cpy[i] == s2_cpy[i])
		i++;
	if (i == n)
		return (0);
	return (s1_cpy[i] - s2_cpy[i]);
}
