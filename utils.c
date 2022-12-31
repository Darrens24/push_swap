
#include "push_swap.h"

t_chained	*null_list(void)
{
	return (NULL);
}

int	is_empty(t_chained *list)
{
	if (list->nb_elem == 0 || !list)
		return (1);
	return (0);
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

int		is_sorted(t_chained *list)
{
	t_node	*tmp;

	tmp = list->start;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		list_has_sup_med(t_data *data, t_chained *list)
{
	t_node	*temp;

	temp = list->start;
	while (temp)
	{
		if (temp->data > data->medium)
			return (1);
		temp = temp->next;
	{
	return (0);
}
