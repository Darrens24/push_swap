/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:35 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/06 10:44:36 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chained	*push_without_print(t_chained *from, t_chained *to)
{
	int	buf;

	if (is_empty(from))
		return (null_list());
	buf = from->start->data;
	remove_front_node(from);
	new_front_node(to, buf);
	return (to);
}

t_chained	*swap_both_without_print(t_chained *list1, t_chained *list2)
{
	swap_without_print(list1);
	swap_without_print(list2);
	return (list1);
}

t_chained	*reverse_without_print(t_chained *list)
{
	int	buf;

	if (list->nb_elem < 2)
		return (null_list());
	buf = list->end->data;
	list = remove_back_node(list);
	list = new_front_node(list, buf);
	return (list);
}

t_chained	*reverse_both_printless(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	if (list1->nb_elem < 2 || list2->nb_elem < 2)
		return (null_list());
	buf1 = list1->end->data;
	list1 = remove_back_node(list1);
	list1 = new_front_node(list1, buf1);
	buf2 = list2->end->data;
	list2 = remove_back_node(list2);
	list2 = new_front_node(list2, buf2);
	return (list2);
}
