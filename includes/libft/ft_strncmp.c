/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:47:30 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 20:06:33 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int i;

	i = 0;
	while (*s1 == *s2 && *s1 && *s2 && i < (int)n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (n)
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	return (0);
}
