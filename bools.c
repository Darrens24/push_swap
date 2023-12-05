/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:07:43 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/19 09:09:09 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_data_in_step(t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp)
	{
		if (temp->data < list->next_step)
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

int	biggest_or_second_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp && temp->data != is_biggest(list)
		&& temp->data != is_second_biggest(list))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	biggest_or_second_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp && temp->data != is_biggest(list)
		&& temp->data != is_second_biggest(list))
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

int	is_second_biggest(t_chained *list)
{
	t_node	*temp;
	int		big;

	temp = list->start;
	big = -2147483648;
	while (temp)
	{
		if (temp && temp->data > big && temp->data < is_biggest(list))
			big = temp->data;
		temp = temp->next;
	}
	return (big);
}
