/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:33:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/03 14:55:24 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*low_data(t_data *data)
{
	while (list_has_low_med(data->medium, data->a))
	{
		if (data->a->start->data <= data->medium)
		{
			push(data->a, data->b);
			if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
				swap_top(data->b);
			else if (data->b->nb_elem > 1 && data->a->start->data > data->medium)
				rotate_both(data->a, data->b);
		}
		else
			rotate(data->a);
	}
		while ((!is_sorted(data->a)) || (!is_reverse_sorted(data->b)))
	{
		if (data->a->start->next->data < data->a->start->data && data->b->start->next->data > data->b->start->data)
			swap_both(data->a, data->b);
		else if (data->a->start->next->data < data->a->start->data)
		{
			data->a = swap_top(data->a);
			if (data->a->nb_elem > 2)
				rotate(data->a);
		}
		else if (data->b->start->next->data > data->b->start->data)
		{
			data->b = swap_top(data->b);
			if (data->b->nb_elem > 2)
				rotate(data->b);
		}
		else if (data->a->start->data > data->a->end->data && data->b->start->data < data->b->end->data)
			rotate_both(data->a, data->b);
		else if (!is_sorted(data->a))
			reverse(data->a);
		else if (!is_reverse_sorted(data->b))
			reverse(data->b);
	}
	while (!is_empty(data->b))
		data->a = push(data->b, data->a);
	return (data->a);
}
/*
t_chained	*medium_data(t_data *data)
{

}

t_chained	*high_data(t_data *data)
{

}
*/
