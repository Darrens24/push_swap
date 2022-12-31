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

t_chained	*new_front_node(t_chained *list, int data)
{
	t_node	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
	{
		ft_putstr_fd("Error\nDynamic allocation failed", 2);
		return (null_list());
	}
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	if (is_empty(list))
	{
		list->start = elem;
		list->end = elem;
	}
	else
	{
		list->start->prev = elem;
		elem->next = list->start;
		list->start = elem;
	}
	list->nb_elem++;
	return (list);
}

t_chained	*new_back_node(t_chained *list, int data)
{
	t_node	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
	{
		ft_putstr_fd("Error\nDynamic allocation failed", 2);
		return (null_list());
	}
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	if (is_empty(list))
	{
		list->start = elem;
		list->end = elem;
	}
	else
	{
		list->end->next = elem;
		elem->prev = list->end;
		list->end = elem;
	}
	list->nb_elem++;
	return (list);
}

t_chained	*remove_front_node(t_chained *list)
{
	t_node	*temp;

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
	temp = list->start;
	list->start = list->start->next;
	list->start->prev = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
	temp = NULL;
	list->nb_elem--;
	return (list);
}


t_chained	*remove_back_node(t_chained *list)
{
	t_node	*temp;

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
	temp = list->end;
	list->end = list->end->prev;
	list->end->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
	temp = NULL;
	list->nb_elem--;
	return (list);
}
