/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:33:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/05 17:28:09 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chained	*very_low_data(t_data *data)
{		
		if (is_sorted(data->a))
			return (data->a);
		else if (data->a->start->next->data == is_lowest(data->a) && data->a->end->data == is_biggest(data->a))
			swap_top(data->a);
		else if (data->a->start->data == is_biggest(data->a) && data->a->start->next->data == is_lowest(data->a))
			rotate(data->a);
		else if (data->a->end->data == is_lowest(data->a) && data->a->start->next->data == is_biggest(data->a))
			reverse(data->a);
		else if (data->a->start->next->data == is_biggest(data->a) && data->a->start->data == is_lowest(data->a))
		{
			reverse(data->a);
			swap_top(data->a);
		}
		else if (data->a->start->data == is_biggest(data->a) && data->a->end->data == is_lowest(data->a))
		{
			swap_top(data->a);
			reverse(data->a);
		}
		return (data->a);
}

t_chained	*low_data(t_data *data)
{
	start_fill_b(data);
	middle_sort(data);
	end_fill_a(data);
	return (data->a);
}


t_chained	*medium_data(t_data *data)
{
	data->a->low = is_lowest(data->a);
	data->a->big = is_biggest(data->a);
	data->a->medium = get_medium(data->a);
	data->a->step = ((data->a->big) - (data->a->low)) / 5;
	data->a->next_step = data->a->low + absolute(data->a->step);
		/*
		while (has_data_in_step(data->a))
		{
			if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->a->start->data > data->a->start->next->data && data->b->start->data < data->b->start->next->data)
				swap_both(data->a, data->b);
			else if ((data->b->nb_elem > 1) && data->b->end->data > data->a->start->data)
				rotate(data->b);
			else if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
				swap_top(data->b);
			if (is_in_step(data->a->start->data, data->a))
				push(data->a, data->b);
			else if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && !is_in_step(data->a->start->data, data->a) && data->a->start->next->data < data->b->start->next->data)
				rotate_both(data->a, data->b);
			else
				rotate(data->a);
		}
		while (!is_reverse_sorted(data->b))
		{
			if (data->b->start->next->data > data->b->start->data)
			{
				data->b = swap_top(data->b);
				if (data->b->nb_elem > 2 && (!is_reverse_sorted(data->b)))
					rotate(data->b);
			}
			else if (data->a->start->data > data->a->end->data && data->b->start->data < data->b->end->data)
				rotate_both(data->a, data->b);
			else
				data->b = reverse(data->b);
		}
		*/

	while (data->a->nb_elem > 0)
	{
		while (has_data_in_step(data->a) && (!is_empty(data->a)))
		{
			if (look_from_top(data->a) < look_from_bot(data->a))
			{
				while (!is_in_step(data->a->start->data, data->a))
				{
					if (data->b->nb_elem > 1 && data->b->start->data != is_lowest(data->b))
						rotate_both(data->a, data->b);
					else
						rotate(data->a);
				}
				if (data->a->nb_elem > 0)
					push(data->a, data->b);
	//			if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->b->start < data->b->start->next && data->a->start->data > data->a->start->next->data)
	//				swap_both(data->a, data->b);
	//			else if (data->b->start < data->b->start->next)
	//				swap_top(data->b);
			}
			else if (look_from_top(data->a) >= look_from_bot(data->a))
			{
				while (!is_in_step(data->a->start->data, data->a))
				{
					if (data->b->nb_elem > 1 && data->b->start->data != is_biggest(data->b))
						reverse_both(data->a, data->b);
					else
						reverse(data->a);
				}
				if (data->a->nb_elem > 0)
					push(data->a, data->b);
	//			if (data->b->nb_elem > 1 && data->a->nb_elem > 1 && data->b->start < data->b->start->next && data->a->start->data > data->a->start->next->data)
	//				swap_both(data->a, data->b);
	//			else if (data->b->start < data->b->start->next)
	//				swap_top(data->b);
			}
		}
		data->a->next_step += absolute(data->a->step);
	}
	while (!is_empty(data->b))
	{
		if (biggest_from_top(data->b) < biggest_from_bot(data->b))
		{
			if (data->a->count_second_big == 0)
			{
				while (data->b->start->data != is_biggest(data->b) || data->b->start->data != is_second_biggest(data->b))
					rotate(data->b);
				if (data->b->start->data == is_second_biggest(data->b))
					data->a->count_second_big++;	
				if (data->b->nb_elem > 0)
					push(data->b, data->a);
				if (data->a->count_second_big == 1 && data->a->nb_elem > 1)
				{
					swap_top(data->a);
					data->a->count_second_big--;
				}
			}
			else if (data->a->count_second_big == 1)
			{
				while (data->b->start->data != is_biggest(data->b))
					rotate(data->b);
				if (data->b->nb_elem > 0)
					push(data->b, data->a);
				if (data->a->count_second_big == 1 && data->a->nb_elem > 1)
				{
					swap_top(data->a);
					data->a->count_second_big--;
				}
			}
		}
		else if (biggest_from_top(data->b) >= biggest_from_bot(data->b))
		{
			if (data->a->count_second_big == 0)
			{
				while (data->b->start->data != is_biggest(data->b) || data->b->start->data != is_second_biggest(data->b))
					reverse(data->b);
				if (data->b->start->data == is_second_biggest(data->b))
					data->a->count_second_big++;	
				if (data->a->nb_elem > 0)
					push(data->b, data->a);
				if (data->a->count_second_big == 1 && data->a->nb_elem > 1)
				{
					swap_top(data->a);
					data->a->count_second_big--;
				}
			}
			else if (data->a->count_second_big == 1)
			{
				while (data->b->start->data != is_biggest(data->b))
					reverse(data->b);
				if (data->b->nb_elem > 0)
					push(data->b, data->a);
				if (data->a->count_second_big == 1 && data->a->nb_elem > 1)
				{
					swap_top(data->a);
					data->a->count_second_big--;
				}
			}
		}
	}
	return (data->a);
}
/*		


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
*/
//	end_fill_a(data);


/*	t_node	*index2 = data->a->start;
	printf("Liste a after sorting :\n");
	while (index2)
	{
		printf("[%d]\n", index2->data);
		index2 = index2->next;
	}*/



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
		}*/
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

/*	data->a->next_step += absolute(data->a->step);
	printf("step = %d\n", data->a->next_step);
	}*/
	//middle_sort(data);
//	printf("FIN DU START\n");
	/*middle_sort(data);
	end_fill_a(data);*/
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

