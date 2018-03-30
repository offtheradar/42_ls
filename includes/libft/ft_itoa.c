/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:10:59 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 20:26:28 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n_2;

	str_len = ft_get_int_len(n);
	n_2 = n;
	if (n < 0)
	{
		n_2 = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n_2 % 10 + '0';
	while (n_2 /= 10)
		str[--str_len] = n_2 % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
