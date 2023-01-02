#include "push_swap.h"

int main(int ac, char **av)
{
    t_data  push_swap;
	
    if (!check_errors(av, ac))
		return (0);
	push_swap.a = null_list();
	push_swap.b = null_list();
    get_data(&push_swap, ac, av);
	t_node	*index = push_swap.a->start;
	printf("Liste A Depart :\n");
	while (index)
    {
        printf("[%d]\n", index->data);
		index = index->next;
    }
	push_swap.a = low_data(&push_swap);	
	printf("\n-------------\n");
	t_node	*index2 = push_swap.a->start;
	printf("Liste a after sorting :\n");
	while (index2)
    {
        printf("[%d]\n", index2->data);
		index2 = index2->next;
    }
    return (0);
/*	
	(void)ac, (void)av;
	t_chained	*list = null_list();
	
	list = new_front_node(list, 40);
	list = new_front_node(list, 20);
	list = new_front_node(list, 10);

	t_node	*temp = list->start;
	int i = 0;
	while (temp)
	{
		printf("%d | Nombre d'elements : %d\n", temp->data, list->nb_elem);
		i++;
		temp = temp->next;
	}
	list = remove_front_node(list);
	list = remove_back_node(list);
	t_node	*temp2 = list->start;
	while (temp2)
	{
		printf("%d | Nombre d'elements : %d\n", temp2->data, list->nb_elem);
		temp2 = temp2->next;
	}
	*/
}
