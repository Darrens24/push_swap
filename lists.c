/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:20:54 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/27 13:18:49 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*remove_front_node(t_chained *list)
{
	t_chained	*temp;

	if (is_empty(list))
	{
		ft_putstr_fd("Error\nNothing to free\n", 2);
		return (null_list());
	}
	if (list->start == list->end)
	{
		free(list->start);
		free(list);
		list = NULL;
		return (null_list());
	}
	temp = list;
	free(list->start);
	list->start = temp->start->next;
	list->nb_elem--;
	return (list);
}

/*
t_chained	*remove_back_node(t_chained *list)
{

	return (list);
}
*/
