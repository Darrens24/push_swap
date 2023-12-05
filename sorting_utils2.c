/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:11:14 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/09 13:57:46 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_is_optimal(t_data *data)
{
	while (data->a->nb_elem > 1 && !is_in_step(data->a->start->data, data->a))
		rotate(data->a);
	if (data->a->nb_elem > 0)
	{
		push(data->a, data->b);
		if (data->a->nb_elem > 1 && data->b->nb_elem > 1
			&& data->b->start->data > data->step_median
			&& look_from_top(data->a) < look_from_bot(data->a))
			rotate_both(data->a, data->b);
		else if (data->b->nb_elem > 1
			&& data->b->start->data > data->step_median)
			rotate(data->b);
	}
}

static void	bot_is_optimal(t_data *data)
{
	while (data->a->nb_elem > 1 && !is_in_step(data->a->start->data, data->a))
		reverse(data->a);
	if (data->a->nb_elem > 0)
	{
		push(data->a, data->b);
		if (data->a->nb_elem > 1 && data->b->nb_elem > 1
			&& data->b->start->data > data->step_median
			&& look_from_top(data->a) < look_from_bot(data->a))
			rotate_both(data->a, data->b);
		else if (data->b->start->data > data->step_median
			&& data->b->nb_elem > 1)
			rotate(data->b);
	}
}

void	stepfill_b(t_data *data)
{
	while (!is_empty(data->a))
	{
		while (has_data_in_step(data->a) && (!is_empty(data->a)))
		{
			if (look_from_top(data->a) <= look_from_bot(data->a))
				top_is_optimal(data);
			else if (look_from_top(data->a) > look_from_bot(data->a))
				bot_is_optimal(data);
		}
		data->step_median = data->a->next_step
			+ get_step_median(data->a->next_step, data->a->next_step
				+ absolute(data->a->step));
		data->a->next_step += absolute(data->a->step);
	}
}

void	let_3_in_a(t_data *data)
{
	while (data->a->nb_elem > 3)
	{
		if (lowest_from_top(data->a) <= lowest_from_bot(data->a))
		{
			while (data->a->start->data != is_lowest(data->a))
				rotate(data->a);
			if (data->a->nb_elem > 0)
				push(data->a, data->b);
		}
		else if (lowest_from_top(data->a) > lowest_from_bot(data->a))
		{
			while (data->a->start->data != is_lowest(data->a))
				reverse(data->a);
			if (data->a->nb_elem > 0)
				push(data->a, data->b);
		}
	}
}
