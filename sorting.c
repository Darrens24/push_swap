
#include "push_swap.h"

t_chained	*low_data(t_data *data)
{
	printf("Moyenne = %d\n", data->medium);
	printf("\n-------\n");
	printf("Debut du tri\n");
	while (list_has_low_med(data->medium, data->a))
	{
		if (data->a->start->data < data->medium)
		{
			push(data->a, data->b);
			if (data->b->nb_elem > 1 && data->b->start->data < data->b->start->next->data)
				swap_top(data->b);
			else if (data->b->nb_elem > 1 && data->a->start->data > data->medium)
				rotate_both(data->a, data->b);
		}
		else
			rotate(data->a);
	}
	printf("\n-------\n");
	printf("Les elements sont dans la bonne liste\n");
	t_node	*index = data->a->start;
	printf("Liste a dans le lowdata :\n");
	while (index)
    {
        printf("[%d]\n", index->data);
		index = index->next;
    }
	t_node	*index2 = data->b->start;
	printf("Liste b dans le lowdata :\n");
	while (index2)
    {
        printf("[%d]\n", index2->data);
		index2 = index2->next;
    }

	printf("Debut du rangement\n");
	printf("sorted : %d\nreverse : %d\n", is_sorted(data->a), is_reverse_sorted(data->b));
	while ((!is_sorted(data->a)) || (!is_reverse_sorted(data->b)))
	{
		if (data->a->start->next->data > data->a->start->data && data->b->start->next->data < data->b->start->data)
			swap_both(data->a, data->b);
		else if (data->a->start->data > data->a->end->data && data->b->start->data < data->b->end->data)
			rotate_both(data->a, data->b);
		else if (data->a->start->next->data < data->a->start->data)
			swap_top(data->a);
		else if (data->b->start->next->data > data->b->start->data)
			swap_top(data->b);
		if (!is_reverse_sorted(data->b)&& !is_sorted(data->a))
				rotate_both(data->a, data->b);
		else if (!is_sorted(data->a))
			rotate(data->a);
		else if (!is_reverse_sorted(data->b))
			rotate(data->b);
	}
		printf("coucou du rangement\n");
	while (!is_empty(data->b))
		push(data->b, data->a);
	printf("\n-------\n");
	printf("Les elements sont tries\n");
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
