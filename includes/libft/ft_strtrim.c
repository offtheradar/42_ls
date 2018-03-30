/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:54:17 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:12:57 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len_w_o_space;

	if (!s)
		return (NULL);
	start = 0;
	while (WHITESPACE(s[start]))
		start++;
	if (!(s[start]))
		return (ft_strdup((char*)(s + start)));
	len_w_o_space = (size_t)ft_strlen((char*)s) - 1;
	while (WHITESPACE(s[len_w_o_space]) && len_w_o_space)
		len_w_o_space--;
	return (ft_strsub(s, start, len_w_o_space - start + 1));
}
