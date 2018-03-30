/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:43:34 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:05:45 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		len_s1;
	char	*s2;
	char	*start;

	len_s1 = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (!s2)
		return (NULL);
	start = s2;
	while (*s1)
	{
		*s2 = *s1;
		s1++;
		s2++;
	}
	*s2 = '\0';
	return (start);
}
