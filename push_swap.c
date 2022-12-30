/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:36 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/27 12:18:01 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*null_list(void)
{
	return (NULL);
}

int	is_empty(t_chained *list)
{
	if (list->nb_elem == 0)
		return (1);
	return (0);
}

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

int	get_data(t_data *data, int ac, char **av)
{
	int	i;
	int	res;

	data->nb_elem = ac - 1;
	i = 0;
	res = 0;
	data->a = malloc(sizeof(*data->a));
	if (!data->a)
	{
		ft_putstr_fd("Error\nDynamic allocation failed", 2);
		return (-1);
	}
	data->b = malloc(sizeof(*data->b));
	if (!data->b)
	{
		ft_putstr_fd("Error\nDynamic allocation failed", 2);
		return (-1);
	}
	while (i < data->nb_elem)
	{
		data->a = new_back_node(data->a, ft_atoi(av[i + 1]));
		res += data->a->start->data;
		i++;
	}
	data->medium = (res / data->nb_elem);
	return (0);
}
