/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:18:55 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 19:45:43 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**output_str;
	int		i;
	int		j;
	int		k;

	if (!s || !(output_str = (char**)malloc(sizeof(*output_str) *
					(ft_count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_count_words(s, c))
	{
		k = 0;
		if (!(output_str[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			output_str[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			output_str[i][k++] = s[j++];
		output_str[i][k] = '\0';
	}
	output_str[i] = 0;
	return (output_str);
}
