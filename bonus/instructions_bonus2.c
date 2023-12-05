/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:44:23 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/06 10:44:33 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chained	*rotate_without_print(t_chained *list)
{
	int	buf;

	if (list->nb_elem < 2)
		return (null_list());
	buf = list->start->data;
	remove_front_node(list);
	new_back_node(list, buf);
	return (list);
}

t_chained	*rotate_both_printless(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	if (list1->nb_elem < 2 || list2->nb_elem < 2)
		return (null_list());
	buf1 = list1->start->data;
	list1 = remove_front_node(list1);
	list1 = new_back_node(list1, buf1);
	buf2 = list2->start->data;
	list2 = remove_front_node(list2);
	list2 = new_back_node(list2, buf2);
	return (list2);
}
