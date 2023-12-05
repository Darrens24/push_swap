/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:45 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/06 11:00:54 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_strchained	*new_back_node_str(t_strchained *list, char *str)
{
	t_strnode	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->str = ft_strdup(str);
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

t_strchained	*remove_back_node_str(t_strchained *list)
{
	t_strnode	*temp;

	if (list->nb_elem == 0)
		return (NULL);
	if (list->nb_elem == 1)
	{
		list->nb_elem--;
		free(list->end->str);
		free(list->end);
		list->end = NULL;
		return (list);
	}
	temp = list->end;
	list->end = list->end->prev;
	list->end->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp->str);
	free(temp);
	temp = NULL;
	list->nb_elem--;
	return (list);
}

int	input_is_correct(t_strchained *input)
{
	t_strnode	*temp;

	temp = input->start;
	while (temp)
	{
		if (temp && temp->str && compare_with_valids(temp->str))
			temp = temp->next;
	}
	return (1);
}
