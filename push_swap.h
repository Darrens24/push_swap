/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:06:17 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/05 17:00:33 by eleleux          ###   ########.fr       */
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
	int				medium;
	int				low;
	int				big;
	int				count_second_big;
	int				step;
	int				next_step;
	struct s_node	*start;
	struct s_node	*end;
}				t_chained;

typedef struct s_data
{
	int			nb_elem;
	int			medium;
	t_chained	*a;
	t_chained	*b;
}				t_data;

//List Manipulation
t_chained	*null_list(void); //ok
int			is_empty(t_chained *list); //ok
t_node		*go_to_end(t_chained *list);
t_chained	*new_front_node(t_chained *list, int data); //ok
t_chained	*new_back_node(t_chained *list, int data);//ok
t_chained	*remove_front_node(t_chained *list);//ok
t_chained	*remove_back_node(t_chained *list);//ok

//Data
long	ft_atol(char *str);
int		get_medium(t_chained *list);
int		is_lowest(t_chained *list);
int		is_biggest(t_chained *list);
int		is_second_biggest(t_chained *list);
int		get_data(t_data *data, int ac, char **av);//ok
void	free_data(t_data *data);
int		is_sorted(t_chained *list);
int		is_reverse_sorted(t_chained *list);
int		list_has_sup_med(t_data *data, t_chained *list);
int		list_has_low_med(int med, t_chained *list);
int		node_is_sup_med(t_data *data, t_node *node);
int		has_data_in_step(t_chained *list);
int		is_in_step(int data, t_chained *list);
int		absolute(int data);

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

//Sorting Algoritm
void		start_fill_b(t_data *data);
void		middle_sort(t_data *data);
void		end_fill_a(t_data *data);
t_chained	*very_low_data(t_data *data);
t_chained	*low_data(t_data *data);
t_chained	*medium_data(t_data *data);
t_chained	*high_data(t_data *data);
int			look_from_top(t_chained *list);
int			look_from_bot(t_chained *list);
int			biggest_from_top(t_chained *list);
int			biggest_from_bot(t_chained *list);

#endif
