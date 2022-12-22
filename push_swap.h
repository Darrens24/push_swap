/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:06:17 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/21 18:32:08 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int     		data;
	char			c;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	int		nb_args;
	int		medium;
	int		*tab;
	t_stack	a;
	t_stack	b;

}				t_data;

//Data
int	get_data(t_data *data, int ac, char **av);

//Errors
int	check_double(int *tab, int ac);
int	check_errors(int *tab, int ac);

//Instructions
int	swap_top(t_stack *stack);
int	swap_both(t_stack *stack1, t_stack *stack2);
int	push(t_stack *from, t_stack *to);
int	rotate(t_stack *stack);
int	rotate_both(t_stack *stack1, t_stack *stack2);
int	reverse(t_stack *stack);
int	reverse_both(t_stack *stack1, t_stack *stack2);

#endif