/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:34:46 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 17:06:29 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*reverse(t_chained *list)
{
	int	buf;

	buf = list->end->data;
	list = remove_back_node(list);
	list = new_front_node(list, buf);
	ft_printf("rr%c\n", list->name);
	return (list);
}

t_chained	*reverse_both(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	if (is_empty(list1))
		return (null_list());
	buf1 = list1->end->data;
	list1 = remove_back_node(list1);
	list1 = new_front_node(list1, buf1);
	buf2 = list2->end->data;
	list2 = remove_back_node(list2);
	list2 = new_front_node(list2, buf2);
	ft_printf("rrr\n");
	return (list2);
}

t_chained	*rotate(t_chained *list)
{
	int	buf;

	buf = list->start->data;
	remove_front_node(list);
	new_back_node(list, buf);
	ft_printf("r%c\n", list->name);
	return (list);
}

t_chained	*rotate_both(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	ft_printf("rr\n");
	buf1 = list1->start->data;
	list1 = remove_front_node(list1);
	list1 = new_back_node(list1, buf1);
	buf2 = list2->start->data;
	list2 = remove_front_node(list2);
	list2 = new_back_node(list2, buf2);
	return (list2);
}
