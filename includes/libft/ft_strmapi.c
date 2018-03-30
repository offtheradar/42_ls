/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:26:42 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/23 23:01:38 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_otpt;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(str_otpt = ft_strnew(ft_strlen((char*)s))))
		return (NULL);
	while (s[i])
	{
		str_otpt[i] = f(i, s[i]);
		i++;
	}
	return (str_otpt);
}
