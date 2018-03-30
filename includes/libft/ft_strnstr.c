/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:54:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:31:46 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tester(const char *ndl, const char *hs, int *i, int n)
{
	char	*hay_match;
	int		j;

	j = 0;
	hay_match = (char *)hs;
	while (*ndl && *(ndl) == *(hs) && j < n && (*i + j) < n)
	{
		ndl++;
		hs++;
		j++;
	}
	if (*ndl == '\0')
		return (hay_match);
	return (NULL);
}

char		*ft_strnstr(const char *hs, const char *ndl, unsigned int n)
{
	char			*start_ndl;
	char			*hay_match;
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen((char *)ndl) == 0)
		return ((char*)hs);
	start_ndl = (char*)ndl;
	i = 0;
	while (*hs && i < n)
	{
		hay_match = (char*)hs;
		j = 0;
		if (*hs == *start_ndl)
			if (tester(ndl, hs, (int *)&i, n) == hay_match)
				return (hay_match);
		hs++;
		i++;
	}
	return (0);
}
