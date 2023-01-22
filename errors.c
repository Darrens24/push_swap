/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:31:56 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 14:27:30 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][0] != '-')
			{
				ft_putstr_fd("Error\nProgram only accepts digits.\n", 2);
				return (0);
			}
		j++;
		}
	i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	i;
	long	res;
	long	minus;

	i = 0;
	res = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus *= (-1);
		i++;
	}
	while (str[i])
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * minus);
}

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

int	check_is_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i <= (ac - 1))
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
		{
			ft_putstr_fd("Error\nData needs to be in integer range.\n", 2);
			return (0);
		}
	i++;
	}
	return (1);
}

int	check_errors(char **av, int ac)
{
	if (ac < 3)
	{
		ft_putstr_fd("Error\nProgram needs at least 2 arguments.\n", 2);
		return (0);
	}
	if (!check_double(av, ac) || !check_is_digit(av) || !check_is_int(ac, av))
		return (0);
	return (1);
}
