/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:10:33 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 20:15:22 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst_cpy;
	size_t	i;

	i = 0;
	dst_cpy = dst;
	while (i < n)
	{
		dst_cpy[i] = ((char*)src)[i];
		if (((char*)src)[i] == (char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
