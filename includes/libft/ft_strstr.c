/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:03:32 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 00:17:51 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*start_needle;
	char	*hay_match;

	if (ft_strlen((char *)needle) == 0)
		return ((char*)haystack);
	hay_match = (char*)haystack;
	start_needle = (char*)needle;
	while (*haystack)
	{
		hay_match = (char*)haystack;
		needle = start_needle;
		if (*haystack == *start_needle)
		{
			while (*needle && *needle == *haystack)
			{
				needle++;
				haystack++;
			}
			if (*needle == '\0')
				return (hay_match);
		}
		haystack = hay_match;
		haystack++;
	}
	return (0);
}
