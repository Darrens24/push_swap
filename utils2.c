#include "push_swap.h"

t_node	*go_to_end(t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

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

int	has_data_in_step(t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp)
	{
		if (temp->data <= list->next_step)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		is_in_step(int data, t_chained *list)
{
	if (data <= list->next_step)
		return (1);
	return (0);
}

int	absolute(int data)
{
	if (data < 0)
		return (data * -1);
	return (data);
}

int			look_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp->data > list->next_step)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int			look_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp->data > list->next_step)
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

int	biggest_from_top(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->start;
	i = 0;
	while (temp->data != is_biggest(list) || temp->data != is_second_biggest(list))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	biggest_from_bot(t_chained *list)
{
	t_node	*temp;
	int		i;

	temp = list->end;
	i = 0;
	while (temp->data != is_biggest(list) || temp->data != is_second_biggest(list))
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

int		is_second_biggest(t_chained *list)
{
	t_node	*temp;
	int		big;

	temp = list->start;
	big = -2147483648;
	while (temp)
	{
		if (temp->data > big && temp->data < is_biggest(list))
			big = temp->data;
		temp = temp->next;
	}
	return (big);
}
