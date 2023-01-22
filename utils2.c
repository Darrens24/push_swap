/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:56:14 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 17:00:13 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int data)
{
	if (data < 0)
		return (data * -1);
	return (data);
}

int	biggest_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp->data != is_biggest(list))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	biggest_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp->data != is_biggest(list))
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

int	lowest_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp->data != is_lowest(list))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	lowest_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp->data != is_lowest(list))
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}
