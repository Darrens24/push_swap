/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:31:56 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/09 15:38:23 by eleleux          ###   ########.fr       */
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
		if (av[i][0] == '-')
			j++;
		if (!av[i][j])
			return (ft_putstr_fd("Error\n", 2), 0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(int *int_array, int ac)
{
	int	size;
	int	i;
	int	j;

	size = ac - 1;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (int_array[i] == int_array[j])
				return (ft_putstr_fd("Error\n", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (ac - 1))
	{
		j = 0;
		av[i] = trim_zeros(av[i]);
		if (ft_strlen(av[i]) < 10)
		{
			i++;
			continue ;
		}
		else if (av[i][0] == '-')
		{
			if (ft_strlen(av[i]) > 11)
				return (ft_putstr_fd("Error\n", 2), 0);
		}
		else if (ft_strlen(av[i]) > 10)
			return (ft_putstr_fd("Error\n", 2), 0);
		if (!check_good_len(av, i, j))
			return (0);
		i++;
	}
	return (1);
}

int	get_args_array_check_double(int ac, char **av)
{
	int	*int_array;
	int	i;
	int	j;

	int_array = malloc(sizeof(int) * (ac - 1));
	if (!int_array)
		return (0);
	i = 1;
	j = 0;
	while (av[i])
		int_array[j++] = ft_atoi(av[i++]);
	if (!check_double(int_array, ac))
		return (free(int_array), 0);
	free(int_array);
	return (1);
}

int	check_errors(char **av, int ac)
{
	if (ac < 2)
		return (0);
	if (!check_is_digit(av) || !check_is_int(ac, av))
		return (0);
	if (!get_args_array_check_double(ac, av))
		return (0);
	return (1);
}
