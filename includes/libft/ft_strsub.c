/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:44:49 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:11:17 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[(size_t)start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
