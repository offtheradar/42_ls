/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:09:56 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/24 20:26:57 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_islower(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

static int		ft_isupper(int c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

int				ft_isalpha(int c)
{
	return ((ft_islower(c) || ft_isupper(c)) ? 1 : 0);
}
