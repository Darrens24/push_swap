
#include "push_swap.h"

t_chained	*low_data(t_data *data)
{
	printf("Moyenne = %d\n", data->medium);
	while (list_has_sup_med(data, data->b))
	{
		while (data->a->nb_elem > data->nb_elem * 40 / 100)
		{
			if (data->a->start->data < data->medium)
				push(data->a, data->b);
			else if ((!is_empty(data->b)) && data->b->nb_elem > 1 && (data->b->start->data < data->b->start->next->data) && (data->a->start->data > data->medium))
				rotate_both(data->a, data->b);
			else
				rotate(data->a);
			printf("coucou du lowdata\n");
		}
	}
	while (!is_empty(data->b))
		push(data->b, data->a);
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
