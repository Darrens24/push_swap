#include "push_swap.h"

t_chained	*reverse(t_chained *list)
{
	int	buf;

	if (is_empty(list))
		return (null_list());
	buf = list->end->data;
	list = remove_back_node(list);
	list = new_front_node(list, buf);
	ft_printf("rr%c\n", list->name);
	return (list);
}

t_chained	*reverse_both(t_chained *list1, t_chained *list2)
{
	int	buf1;
	int	buf2;

	if (is_empty(list1))
		return (null_list());
	buf1 = list1->end->data;
	list1 = remove_back_node(list1);
	list1 = new_front_node(list1, buf1);
	buf2 = list2->end->data;
	list2 = remove_back_node(list2);
	list2 = new_front_node(list2, buf2);
	ft_printf("rrr\n");
	return (list2);
}
