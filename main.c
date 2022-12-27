#include "push_swap.h"

int main(int ac, char **av)
{
/*    t_data  push_swap;
    int i = 0;

    if (ac < 2)
        return (0);
    get_data(&push_swap, ac, av);
    check_double(push_swap.tab, ac);
    while (i < push_swap.nb_elem)
    {
        printf("[%d]\n", push_swap.tab[i++]);
    }
    printf("%d\n", push_swap.medium);
    return (0);
	*/
	
	(void)ac, (void)av;
	t_chained	*list = null_list();
	
	list = new_front_node(list, 40);
	list = new_front_node(list, 20);
	list = new_front_node(list, 10);

	t_node	*temp = list->start;
	int i = 0;
	while (temp)
	{
		printf("%d element = %d | Nombre d'elements : %d\n", i, temp->data, list->nb_elem);
		i++;
		temp = temp->next;
	}
	list = remove_front_node(list);
	list = remove_front_node(list);
	list = remove_front_node(list);
	t_node	*temp2 = list->start;
	while (temp2 != NULL)
	{
		printf("%d | Nombre d'elements : %d\n", temp2->data, list->nb_elem);
		temp2 = temp2->next;
	}
	return (0);
}
