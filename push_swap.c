/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:36 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/21 18:50:45 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_data(t_data *data, int ac, char **av)
{
	int	i;
	int	res;

	data->nb_args = ac - 1;
	data->tab = malloc(sizeof(int) * data->nb_args); //FREE
	i = 0;
	res = 0;
	while (i < data->nb_args)
	{
		data->tab[i] = ft_atoi(av[i + 1]);
		res += data->tab[i];
		i++;
	}
	data->medium = (res / data->nb_args);
	return (0);
}