/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:33:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/09 13:53:20 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*very_low_data(t_data *data)
{		
	if (is_sorted(data->a))
		return (data->a);
	else if (data->a->start->next->data == is_lowest(data->a)
		&& data->a->end->data == is_biggest(data->a))
		swap_top(data->a);
	else if (data->a->start->data == is_biggest(data->a)
		&& data->a->start->next->data == is_lowest(data->a))
		rotate(data->a);
	else if (data->a->end->data == is_lowest(data->a)
		&& data->a->start->next->data == is_biggest(data->a))
		reverse(data->a);
	else if (data->a->start->next->data == is_biggest(data->a)
		&& data->a->start->data == is_lowest(data->a))
	{
		reverse(data->a);
		swap_top(data->a);
	}
	else if (data->a->start->data == is_biggest(data->a)
		&& data->a->end->data == is_lowest(data->a))
	{
		swap_top(data->a);
		reverse(data->a);
	}
	return (data->a);
}

t_chained	*low_data(t_data *data)
{
	let_3_in_a(data);
	very_low_data(data);
	fill_back_a(data);
	return (data->a);
}

int	get_step_median(int low, int high)
{
	return (absolute(high - low) / 2);
}

t_chained	*medium_data(t_data *data)
{
	data->a->low = is_lowest(data->a);
	data->a->big = is_biggest(data->a);
	data->a->medium = get_medium(data->a);
	data->a->step = ((data->a->big) - (data->a->low)) / 4;
	data->a->next_step = data->a->low + absolute(data->a->step);
	data->step_median = data->a->low + get_step_median(data->a->low,
			data->a->next_step);
	stepfill_b(data);
	fill_back_a(data);
	return (data->a);
}

t_chained	*high_data(t_data *data)
{
	data->a->low = is_lowest(data->a);
	data->a->big = is_biggest(data->a);
	data->a->medium = get_medium(data->a);
	data->a->step = ((data->a->big) - (data->a->low)) / 9;
	data->a->next_step = data->a->low + absolute(data->a->step);
	data->step_median = data->a->low + get_step_median(data->a->low,
			data->a->next_step);
	stepfill_b(data);
	fill_back_a(data);
	return (data->a);
}
