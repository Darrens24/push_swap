/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:31:56 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/21 18:41:00 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < (ac - 1))
	{
		j = i + 1;
		while (j < (ac - 1))
		{
			if (tab[i] == tab[j])
			{
				ft_printf("Error\nData contains duplicates !\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
int	check_errors(int *tab, int ac)
{

}
*/