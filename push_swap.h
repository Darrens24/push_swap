/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darrensdev <darrensdev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:06:17 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/27 12:29:03 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int     		data;
	struct s_node	*next;
}				t_node;

typedef struct s_chained
{
	int				nb_elem;
	struct s_node	*start;
	struct s_node	*end;
}				t_chained;

typedef struct s_data
{
	int			nb_elem;
	int			medium;
	int			*tab;
	t_chained	*a;
	t_chained	*b;

}				t_data;

//List Manipulation
t_chained	*null_list(void); //ok
int			is_empty(t_chained *list); //ok
t_chained	*new_front_node(t_chained *list, int data);
t_chained	*new_back_node(t_chained *list, int data);
t_chained	*remove_front_node(t_chained *list);
t_chained	*remove_back_node(t_chained *list);
void		fill_a(t_data *data);

//Data
int	get_data(t_data *data, int ac, char **av);

//Errors
int	check_double(int *tab, int ac);
int	check_errors(int *tab, int ac);

//Instructions
int	swap_top(t_chained *stack);
int	swap_both(t_chained *stack1, t_chained *stack2);
int	push(t_chained *from, t_chained *to);
int	rotate(t_chained *stack);
int	rotate_both(t_chained *stack1, t_chained *stack2);
int	reverse(t_chained *stack);
int	reverse_both(t_chained *stack1, t_chained *stack2);

#endif
