/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:45 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/04 15:58:12 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_medium(t_chained *list)
{
	t_node	*temp;
	int		res;
	int		medium;

	res = 0;
	medium = 0;
	temp = list->start;
	while (temp)
	{
		res += temp->data;
		temp = temp->next;
	}
	medium = res / list->nb_elem;
	return (medium);
}

int	is_lowest(t_chained *list)
{
	t_node *temp;
	int		low;

	temp = list->start;
	low = 2147483647;
	while (temp)
	{
		if (temp->data < low)
			low = temp->data;
		temp = temp->next;
	}
	return (low);
}

int	is_biggest(t_chained *list)
{
	t_node *temp;
	int		big;

	temp = list->start;
	big = -2147483648;
	while (temp)
	{
		if (temp->data > big)
			big = temp->data;
		temp = temp->next;
	}
	return (big);
}
/*
void		start_fill_b(t_data *data)
{
	data->medium = get_medium(data->a);
	while (list_has_low_med(data->medium, data->a))
	{
//		printf("medium = %d\n", data->medium);
		while (data->a->start->data < data->medium)
		{
			if ((data->b->nb_elem > 1) && data->b->end->data > data->a->start->data)
				rotate(data->b);
			push(data->a, data->b);
			if (data->b->nb_elem < (data->nb_elem / 2) && !list_has_low_med(data->medium, data->a))
				data->medium = get_medium(data->a);
			if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->a->start->data > data->a->start->next->data && data->b->start->data < data->b->start->next->data)
				swap_both(data->a, data->b);
			else if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
				swap_top(data->b);
		}
		if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->a->start->data > data->a->start->next->data && data->b->start->data < data->b->start->next->data)
			swap_both(data->a, data->b);
		else if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
			swap_top(data->b);
		else if (data->b->nb_elem > 1 && data->a->start->data > data->medium && data->b->start->data < data->b->end->data)
			rotate_both(data->a, data->b);
		else
			rotate(data->a);
	}
		if (data->a->start->next->data < data->medium && data->b->nb_elem > 1 && data->b->start->data < data->b->end->data)
			swap_both(data->a, data->b);
		else
			reverse(data->a);*/
/*	printf("Fin du startfill\n");
	printf("\n-------------\n");
	t_node	*index2 = data->a->start;
	printf("Liste a after sorting :\n");
	while (index2)
    {
        printf("[%d]\n", index2->data);
		index2 = index2->next;
    }
	t_node	*index3 = data->b->start;
	printf("Liste b after sorting :\n");
	while (index3)
    {
        printf("[%d]\n", index3->data);
		index3 = index3->next;
    }
}
*/

void		start_fill_b(t_data *data)
{
	t_node	*temp;

	while (data->a->nb_elem > 2)
	{
		temp = data->a->start;
		while (data->a->start->data != is_lowest(data->a))
		{
			if (data->a->end->data == is_lowest(data->a))
				reverse(data->a);
			else if (data->a->end->prev->data == is_lowest(data->a) && data->a->nb_elem == data->nb_elem)
			{
				reverse(data->a);
				reverse(data->a);
			}
			else
				rotate(data->a);
		}
		push(data->a, data->b);
	}
}

void		middle_sort(t_data *data)
{
	while ((!is_sorted(data->a)) || (!is_reverse_sorted(data->b)))
	{
		if (data->a->start->next->data < data->a->start->data && data->b->start->next->data > data->b->start->data)
		{
			swap_both(data->a, data->b);
			reverse_both(data->a, data->b);
		}
		else if (data->a->start->next->data < data->a->start->data)
		{
			data->a = swap_top(data->a);
			if (data->a->nb_elem > 2 && (!is_sorted(data->a)))
				rotate(data->a);
		}
		else if (data->b->start->next->data > data->b->start->data)
		{
			data->b = swap_top(data->b);
			if (data->b->nb_elem > 2 && (!is_reverse_sorted(data->b)))
				rotate(data->b);
		}
		else if (data->a->start->data > data->a->end->data && data->b->start->data < data->b->end->data)
			rotate_both(data->a, data->b);
		else if (!is_sorted(data->a))
			data->a = reverse(data->a);
		else
			data->b = reverse(data->b);
	}
}

void		end_fill_a(t_data *data)
{
	while (!is_empty(data->b))
		push(data->b, data->a);
}

