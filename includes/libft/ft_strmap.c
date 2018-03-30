/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 18:28:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str_otpt;

	if (!s || !f)
	{
		return (NULL);
	}
	if (!(str_otpt = ft_strnew(ft_strlen((char*)s))))
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		str_otpt[i] = f(s[i]);
		i++;
	}
	return (str_otpt);
}
