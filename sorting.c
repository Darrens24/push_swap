/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:33:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/03 19:16:35 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*low_data(t_data *data)
{
	start_fill_b(data);
/*	t_node	*index2 = data->a->start;
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
    }*/
	middle_sort(data);
	/*t_node	*index2 = data->a->start;
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
	*/
	end_fill_a(data);
	return (data->a);
}
/*
t_chained	*medium_data(t_data *data)
{

}

t_chained	*high_data(t_data *data)
{

}
*/
