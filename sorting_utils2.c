/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:11:14 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 16:59:14 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_data_in_step(t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp)
	{
		if (temp->data <= list->next_step)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_in_step(int data, t_chained *list)
{
	if (data <= list->next_step)
		return (1);
	return (0);
}

void	stepfill_b(t_data *data)
{
	while (data->a->next_step < (data->a->big - data->a->step))
	{
		while (has_data_in_step(data->a) && (!is_empty(data->a)))
		{
			if (look_from_top(data->a) <= look_from_bot(data->a))
			{
				while (!is_in_step(data->a->start->data, data->a))
					rotate(data->a);
				if (data->a->nb_elem > 0)
					push(data->a, data->b);
			}
			else if (look_from_top(data->a) > look_from_bot(data->a))
			{
				while (!is_in_step(data->a->start->data, data->a))
					reverse(data->a);
				if (data->a->nb_elem > 0)
					push(data->a, data->b);
			}
		}
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

void	fill_back_a(t_data *data)
{
	while (!is_empty(data->b))
	{
		if (biggest_from_top(data->b) < biggest_from_bot(data->b))
		{
			while (data->b->start->data != is_biggest(data->b))
				rotate(data->b);
			if (data->b->nb_elem > 0)
				push(data->b, data->a);
		}
		else if (biggest_from_top(data->b) >= biggest_from_bot(data->b))
		{
			while (data->b->start->data != is_biggest(data->b))
				reverse(data->b);
			if (data->a->nb_elem > 0)
				push(data->b, data->a);
		}
	}
}
