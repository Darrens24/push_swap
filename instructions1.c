
#include "push_swap.h"

t_chained	*swap_top(t_chained *list)
{
	t_node	*temp;
	int		buf;

	if (list->nb_elem < 2)
	{
		ft_printf("Not enough elements for swapping\n");
		return (list);
	}
	temp = list->start->next;
	buf = temp->data;
	free(list->start->next);
	list->start->next = NULL;
	temp->prev = NULL;
	if (list->nb_elem > 2)
	{
		list->start->next = temp->next;
		temp->next->prev = list->start;
	}
	list->nb_elem--;
	list = new_front_node(list, buf);
	ft_printf("s%c\n", list->name);
	return (list);
}

t_chained	*swap_both(t_chained *list1, t_chained *list2)
{
	t_node	*temp1;
	int		buf1;
	t_node	*temp2;
	int		buf2;

	if (list1->nb_elem < 2 || list2->nb_elem < 2)
	{
		ft_printf("Not enough elements to swap\n");
		return (list1);
	}
	temp1 = list1->start->next;
	buf1 = list1->start->next->data;
	free(list1->start->next);
	list1->nb_elem--;
	list1->start->next = NULL;
	temp1->prev = NULL;
	if (list1->nb_elem > 2)
	{
		list1->start->next = temp1->next;
		temp1->next->prev = list1->start;
	}
	list1 = new_front_node(list1, buf1);
	temp2 = list2->start->next;
	buf2 = list2->start->next->data;
	free(list2->start->next);
	list2->nb_elem--;
	list2->start->next = NULL;
	if (list2->nb_elem > 2)
	{
		list2->start->next = temp2->next;
		temp2->next->prev = list2->start;
	}
	list2 = new_front_node(list2, buf2);
	ft_printf("ss\n");
	return (list2);
}

t_chained	*push(t_chained *from, t_chained *to)
{
	int	buf;

	if (is_empty(from))
		return (to);
	buf = from->start->data;
	remove_front_node(from);
	new_front_node(to, buf);
	ft_printf("p%c\n", to->name);
	return (to);
}

t_chained	*rotate(t_chained *list)
{
	int	buf;

	if (list->nb_elem < 1)
	{
		ft_printf("Not enough elements to rotate\n");
		return (list);
	}
	buf = list->start->data;
	list = remove_front_node(list);
	list = new_back_node(list, buf);
	ft_printf("r%c\n", list->name);
	return (list);
}

t_chained	*rotate_both(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	if (list1->nb_elem < 1 || list2->nb_elem < 1)
	{

		ft_printf("Not enough elements to rotate\n");
		return (list1);
	}
	ft_printf("rr\n");
	if (list1->nb_elem == 1)
	{
		buf2 = list2->start->data;
		list2 = remove_front_node(list2);
		list2 = new_back_node(list2, buf2);
		return (list2);
	}
	if (list2->nb_elem == 1)
	{
		buf1 = list1->start->data;
		list1 = remove_front_node(list1);
		list1 = new_back_node(list1, buf1);
		return (list1);
	}
	else
	{
		buf1 = list1->start->data;
		list1 = remove_front_node(list1);
		list1 = new_back_node(list1, buf1);
		buf2 = list2->start->data;
		list2 = remove_front_node(list2);
		list2 = new_back_node(list2, buf2);
	}
	return (list2);
}
