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
	char			name;
	struct s_node	*start;
	struct s_node	*end;
}				t_chained;

typedef struct s_data
{
	int			nb_elem;
	int			medium;
	int			bigger;
	int			lower;
	t_chained	*a;
	t_chained	*b;

}				t_data;

//List Manipulation
t_chained	*null_list(void); //ok
int			is_empty(t_chained *list); //ok
t_chained	*new_front_node(t_chained *list, int data); //ok
t_chained	*new_back_node(t_chained *list, int data);//ok
t_chained	*remove_front_node(t_chained *list);//ok
t_chained	*remove_back_node(t_chained *list);//ok

//Data
long	ft_atol(char *str);
int		get_data(t_data *data, int ac, char **av);//ok
void	free_data(t_data *data);
int		is_sorted(t_chained *list);
int		is_reverse_sorted(t_chained *list);
int		list_has_sup_med(t_data *data, t_chained *list);
int		list_has_low_med(t_data *data, t_chained *list);
int		node_is_sup_med(t_data *data, t_node *node);

//Errors
int	check_double(char **av, int ac);
int	check_is_int(int ac, char **av);
int	check_is_digit(char **av);
int	check_errors(char **av, int ac);

//Instructions
t_chained	*swap_top(t_chained *list);//ok
t_chained	*swap_both(t_chained *list1, t_chained *list2);//ok
t_chained	*push(t_chained *from, t_chained *to);//ok
t_chained	*rotate(t_chained *list);//ok
t_chained	*rotate_both(t_chained *list1, t_chained *list2);//ok
t_chained	*reverse(t_chained *list);
t_chained	*reverse_both(t_chained *list1, t_chained *list2);//ok

//Sorting Algos
t_chained	*low_data(t_data *data);
t_chained	*medium_data(t_data *data);
t_chained	*high_data(t_data *data);

#endif
