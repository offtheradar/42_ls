/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:21:27 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/04 19:11:20 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			split(t_file_info *source, t_file_info **front,
						t_file_info **back)
{
	t_file_info	*fast;
	t_file_info	*slow;

	slow = source;
	fast = source->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

t_file_info		*merge(t_file_info *a, t_file_info *b,
						int (*order)(t_file_info *a, t_file_info *b))
{
	t_file_info	*result;

	result = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (order(a, b) <= 0)
	{
		result = a;
		result->next = merge(a->next, b, order);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next, order);
	}
	return (result);
}

void			merge_sort(t_file_info **root,
							int (*order)(t_file_info *a, t_file_info *b))
{
	t_file_info		*head;
	t_file_info		*a;
	t_file_info		*b;

	head = *root;
	if (head == NULL || head->next == NULL)
		return ;
	split(head, &a, &b);
	merge_sort(&a, order);
	merge_sort(&b, order);
	*root = merge(a, b, order);
}

void			order_lst(t_file_info **root, t_options *opt)
{
	if (opt->r)
	{
		if (opt->t)
			merge_sort(root, f_time_cmp_r);
		else
			merge_sort(root, f_name_cmp_r);
	}
	else if (opt->t)
		merge_sort(root, f_time_cmp);
	else
		merge_sort(root, f_name_cmp);
}
