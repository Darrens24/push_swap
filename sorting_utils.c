/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:40:00 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/18 12:41:18 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_medium(t_chained *list)
{
	t_node	*temp;
	int		res;
	int		medium;

	res = 0;
	medium = 0;
	temp = list->start;
	while (temp)
	{
		res += temp->data;
		temp = temp->next;
	}
	medium = res / list->nb_elem;
	return (medium);
}

int	is_lowest(t_chained *list)
{
	t_node	*temp;
	int		low;

	temp = list->start;
	low = 2147483647;
	while (temp)
	{
		if (temp->data < low)
			low = temp->data;
		temp = temp->next;
	}
	return (low);
}

int	is_biggest(t_chained *list)
{
	t_node	*temp;
	int		big;

	temp = list->start;
	big = -2147483648;
	while (temp)
	{
		if (temp->data > big)
			big = temp->data;
		temp = temp->next;
	}
	return (big);
}

int	look_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp && temp->data > list->next_step)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	look_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp && temp->data > list->next_step)
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}
