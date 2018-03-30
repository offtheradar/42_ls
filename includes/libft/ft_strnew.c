/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 22:43:10 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 20:18:45 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	str[size] = '\0';
	return (str);
}
