/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:20:54 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/03 19:06:00 by eleleux          ###   ########.fr       */
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
	if (list->nb_elem == 0)
	{
		list->start = elem;
		list->end = elem;
		elem->next = NULL;
		elem->prev = NULL;
	}
	else
	{
		list->start->prev = elem;	
		elem->prev = NULL;
		elem->next = list->start;
		list->start = elem;
		list->end = go_to_end(list);
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
	if (list->nb_elem == 0)
	{
		list->start = elem;
		list->end = elem;
		elem->next = NULL;
		elem->prev = NULL;
	}
	else
	{
		list->end->next = elem;
		elem->prev = list->end;
		list->end = elem;
		elem->next = NULL;
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
	if (list->nb_elem == 1)
	{
		free(list->start);
		list->nb_elem--;
		free(list);
		list = NULL;
		return (list);
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
	if (list->nb_elem == 1)
	{
		free(list->end);
		list->nb_elem--;
		free(list);
		list = NULL;
		return (list);
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
