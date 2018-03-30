/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:30:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 17:18:01 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_cpy;
	char	*dst_cpy;
	size_t	i;

	i = 0;
	src_cpy = (char*)src;
	dst_cpy = (char *)dst;
	if (src_cpy < dst_cpy)
	{
		while (len--)
			dst_cpy[len] = src_cpy[len];
	}
	else
		ft_memcpy(dst_cpy, src_cpy, len);
	return (dst_cpy);
}
