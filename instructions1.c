/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:27:55 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 14:34:38 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*swap_top(t_chained *list)
{
	t_node	*temp;
	int		buf;

	if (list->nb_elem < 2)
	{
		ft_printf("Not enough elements for swapping\n");
		return (list);
	}
	temp = list->start->next;
	buf = temp->data;
	free(list->start->next);
	list->start->next = NULL;
	temp->prev = NULL;
	if (list->nb_elem > 2)
	{
		list->start->next = temp->next;
		temp->next->prev = list->start;
	}
	list->nb_elem--;
	list = new_front_node(list, buf);
	ft_printf("s%c\n", list->name);
	return (list);
}

t_chained	*swap_both(t_chained *list1, t_chained *list2)
{
	swap_without_print(list1);
	swap_without_print(list2);
	ft_printf("ss\n");
	return (list1);
}

void	swap_without_print(t_chained *list1)
{
	t_node	*temp1;
	int		buf1;

	temp1 = list1->start->next;
	buf1 = list1->start->next->data;
	free(list1->start->next);
	list1->start->next = NULL;
	temp1->prev = NULL;
	if (list1->nb_elem > 2)
	{
		list1->start->next = temp1->next;
		temp1->next->prev = list1->start;
	}
	list1->nb_elem--;
	list1 = new_front_node(list1, buf1);
}

t_chained	*push(t_chained *from, t_chained *to)
{
	int	buf;

	if (is_empty(from))
		return (null_list());
	buf = from->start->data;
	remove_front_node(from);
	new_front_node(to, buf);
	ft_printf("p%c\n", to->name);
	return (to);
}
