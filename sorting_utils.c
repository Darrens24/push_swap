/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:45 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/03 19:37:51 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		start_fill_b(t_data *data)
{
	printf("%d\n", data->medium);
	while (list_has_low_med(data->medium, data->a))
	{
		if (data->a->start->data < data->medium)
		{
			push(data->a, data->b);
			if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->a->start->data > data->a->start->next->data && data->b->start->data < data->b->start->next->data)
				swap_both(data->a, data->b);
			else if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
				swap_top(data->b);
			else if (data->b->nb_elem > 1 && data->a->start->data > data->medium &&data->b->start->data < data->b->end->data)
				rotate_both(data->a, data->b);
		}
		else if (data->a->start->next->data < data->medium && data->b->nb_elem > 1 && data->b->start->data < data->b->end->data)
			swap_both(data->a, data->b);
		else
			rotate(data->a);
	}
}

void		middle_sort(t_data *data)
{
	while ((!is_sorted(data->a)) || (!is_reverse_sorted(data->b)))
	{
		if (data->a->start->next->data < data->a->start->data && data->b->start->next->data > data->b->start->data)
		{
			swap_both(data->a, data->b);
			reverse_both(data->a, data->b);
		}
		else if (data->a->start->next->data < data->a->start->data)
		{
			data->a = swap_top(data->a);
			if (data->a->nb_elem > 2)
				reverse(data->a);
		}
		else if (data->b->start->next->data > data->b->start->data)
		{
			data->b = swap_top(data->b);
			if (data->b->nb_elem > 2)
				reverse(data->b);
		}
		else if (data->a->start->data > data->a->end->data && data->b->start->data < data->b->end->data)
			rotate_both(data->a, data->b);
		else if (!is_sorted(data->a))
			data->a = rotate(data->a);
		else
			data->b = rotate(data->b);
/*
		t_node *index = data->b->start;
		while (index)
    	{
       		printf("[%d]\n", index->data);
			index = index->next;
   		}*/
	}
}

void		end_fill_a(t_data *data)
{
	while (!is_empty(data->b))
		push(data->b, data->a);
}

