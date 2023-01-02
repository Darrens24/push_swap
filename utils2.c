#include "push_swap.h"

int	node_is_sup_med(t_data *data, t_node *node)
{
	if (node->data > data->medium)
		return (1);
	return (0);
}

int	list_has_low_med(int med, t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp)
	{
		if (temp->data < med)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_reverse_sorted(t_chained *list)
{
	t_node	*tmp;

	tmp = list->start;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
