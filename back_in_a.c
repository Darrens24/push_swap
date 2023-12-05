/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:36:58 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/19 10:43:54 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_from_top(t_data *data, int *count)
{
	while (data->b->start->data != is_biggest(data->b))
		rotate(data->b);
	if (data->b->nb_elem > 0)
		push(data->b, data->a);
	if (*count == 1 && data->a->nb_elem > 1
		&& data->b->nb_elem > 1
		&& (data->b->start->next->data == is_biggest(data->b)
			|| data->b->start->next->data == is_second_biggest(data->b)))
		swap_both(data->a, data->b);
	else if (*count == 1 && data->a->nb_elem > 1)
		swap_top(data->a);
}

static void	reverse_from_bot(t_data *data, int *count)
{
	while (data->b->start->data != is_biggest(data->b))
		reverse(data->b);
	if (data->b->nb_elem > 0)
		push(data->b, data->a);
	if (*count == 1 && data->a->nb_elem > 1
		&& data->b->nb_elem > 1
		&& (data->b->start->next->data == is_biggest(data->b)
			|| data->b->start->next->data == is_second_biggest(data->b)))
		swap_both(data->a, data->b);
	else if (*count == 1 && data->a->nb_elem > 1)
		swap_top(data->a);
}

static void	only_look_top_big(t_data *data, int *count)
{
	if (biggest_from_top(data->b) < biggest_from_bot(data->b))
		rotate_from_top(data, count);
	else if (biggest_from_top(data->b) >= biggest_from_bot(data->b))
		reverse_from_bot(data, count);
	*count = 0;
}

static void	look_for_big_or_second(t_data *data, int *count)
{
	if (biggest_or_second_from_top(data->b)
		< biggest_or_second_from_bot(data->b))
	{
		while (data->b->start->data != is_biggest(data->b)
			&& data->b->start->data != is_second_biggest(data->b))
			rotate(data->b);
		if (data->b->start->data == is_second_biggest(data->b))
			*count = 1;
		if (data->b->nb_elem > 0)
			push(data->b, data->a);
	}
	else if (biggest_or_second_from_top(data->b)
		>= biggest_or_second_from_bot(data->b))
	{
		while (data->b->start->data != is_biggest(data->b)
			&& data->b->start->data != is_second_biggest(data->b))
			reverse(data->b);
		if (data->b->start->data == is_second_biggest(data->b))
			*count = 1;
		if (data->b->nb_elem > 0)
			push(data->b, data->a);
	}
}

void	fill_back_a(t_data *data)
{
	data->count_second_big = 0;
	while (!is_empty(data->b))
	{
		if (data->count_second_big == 0)
			look_for_big_or_second(data, &data->count_second_big);
		else
			only_look_top_big(data, &data->count_second_big);
	}
}
