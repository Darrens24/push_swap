/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:08:03 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/09 14:58:35 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	norm_zeros(int minus, char *str, int *i)
{
	if (minus && *i > 0)
	{
		*i -= 1;
		str[*i] = '-';
	}
	else if (minus && *i > 1)
	{
		*i -= 2;
		str[*i] = '-';
	}
}

char	*trim_zeros(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (str[i] && str[i] == '0' && str[i + 1] == '0')
		i++;
	if ((!str[i + 1] && !minus) || (str[i] == '0' && !str[i + 1]))
		return (str + i);
	if (str[i] == '0')
		i++;
	norm_zeros(minus, str, &i);
	return (str + i);
}

int	check_good_len(char **av, int i, int j)
{
	if (av[i][j] == '-')
	{
		if (ft_strncmp(av[i], "-2147483648", 11) > 0)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	else
	{
		if (ft_strncmp(av[i], "2147483647", 10) > 0)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	return (1);
}
