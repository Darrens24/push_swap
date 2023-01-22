/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:25:33 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/06 17:04:29 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*push_swap;

	push_swap = malloc(sizeof(*push_swap));
	if (!check_errors(av, ac))
		return (-1);
	get_data(push_swap, ac, av);
	if (is_sorted(push_swap->a))
		return (0);
	if (ac > 2 && ac < 5)
		push_swap->a = very_low_data(push_swap);
	else if (ac >= 5 && ac < 50)
		push_swap->a = low_data(push_swap);
	else if (ac >= 50 && ac < 400)
		push_swap->a = medium_data(push_swap);
	else if (ac >= 400)
		push_swap->a = high_data(push_swap);
	return (0);
}
