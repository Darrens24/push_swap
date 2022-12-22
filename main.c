#include "push_swap.h"

int main(int ac, char **av)
{
    t_data  push_swap;
    int i = 0;

    get_data(&push_swap, ac, av);
    check_double(push_swap.tab, ac);
    while (i < push_swap.nb_args)
    {
        printf("[%d]\n", push_swap.tab[i++]);
    }
    printf("%d\n", push_swap.medium);
    return (0);
}