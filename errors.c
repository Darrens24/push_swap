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

int	check_double(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (ac - 1))
	{
		j = i + 1;
		while (j <= (ac - 1))
		{
			if (!ft_strncmp(av[i], av[j], ft_strlen(av[i]) + 1))
			{
				ft_putstr_fd("Error\nData contains duplicates.\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_errors(char **av, int ac)
{
	(void)av;

	if (ac < 3)
	{
		ft_putstr_fd("Error\nProgram needs at least 2 arguments.\n", 2);
		return (0);
	}
	if (!check_double(av, ac))
		return (0);
	return (1);
}

