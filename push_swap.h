/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:06:17 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/09 13:52:16 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_chained
{
	int				nb_elem;
	char			name;
	int				medium;
	int				low;
	int				big;
	int				step;
	int				next_step;
	struct s_node	*start;
	struct s_node	*end;
}				t_chained;

typedef struct s_strnode
{
	struct s_strnode	*prev;
	char				*str;
	struct s_strnode	*next;
}				t_strnode;

typedef struct s_strchained
{
	struct s_strnode	*start;
	int					nb_elem;
	struct s_strnode	*end;
}				t_strchained;

typedef struct s_data
{
	int			nb_elem;
	int			medium;
	int			step_median;
	int			count_second_big;
	t_chained	*a;
	t_chained	*b;
}				t_data;

int				try_another_median(t_data *data);

//List Manipulation

t_chained		*null_list(void);
int				is_empty(t_chained *list);
t_node			*go_to_end(t_chained *list);
t_chained		*new_front_node(t_chained *list, int data);
t_chained		*new_back_node(t_chained *list, int data);
t_chained		*remove_front_node(t_chained *list);
t_chained		*remove_back_node(t_chained *list);

//Data

long			ft_atol(char *str);
int				get_medium(t_chained *list);
int				is_lowest(t_chained *list);
int				is_biggest(t_chained *list);
int				get_data(t_data *data, int ac, char **av);
void			free_data(t_data *data);
int				is_sorted(t_chained *list);
int				has_data_in_step(t_chained *list);
int				is_in_step(int data, t_chained *list);
int				absolute(int data);

//Errors

int				check_double(int *int_array, int ac);
int				check_is_int(int ac, char **av);
int				check_is_digit(char **av);
int				check_errors(char **av, int ac);
char			*trim_zeros(char *str);
int				check_good_len(char **av, int i, int j);

//Instructions

t_chained		*swap_top(t_chained *list);
t_chained		*swap_both(t_chained *list1, t_chained *list2);
t_chained		*push(t_chained *from, t_chained *to);
t_chained		*rotate(t_chained *list);
t_chained		*rotate_both(t_chained *list1, t_chained *list2);
t_chained		*reverse(t_chained *list);
t_chained		*reverse_both(t_chained *list1, t_chained *list2);
void			swap_without_print(t_chained *list1);

//Sorting Algoritm

void			stepfill_b(t_data *data);
void			let_3_in_a(t_data *data);
void			fill_back_a(t_data *data);
t_chained		*very_low_data(t_data *data);
t_chained		*low_data(t_data *data);
t_chained		*medium_data(t_data *data);
t_chained		*high_data(t_data *data);
int				look_from_top(t_chained *list);
int				look_from_bot(t_chained *list);
int				biggest_from_top(t_chained *list);
int				biggest_from_bot(t_chained *list);
int				lowest_from_top(t_chained *list);
int				lowest_from_bot(t_chained *list);
int				biggest_or_second_from_top(t_chained *list);
int				biggest_or_second_from_bot(t_chained *list);
int				is_second_biggest(t_chained *list);
int				get_step_median(int low, int high);

//Checker

t_strchained	*new_back_node_str(t_strchained *list, char *str);
t_strchained	*remove_back_node_str(t_strchained *list);
t_strchained	*get_stdin_cmds(void);

//Printless Instructions

t_chained		*push_without_print(t_chained *from, t_chained *to);
t_chained		*swap_both_without_print(t_chained *list1, t_chained *list2);
t_chained		*reverse_without_print(t_chained *list);
t_chained		*reverse_both_printless(t_chained *list1, t_chained *list2);
t_chained		*rotate_without_print(t_chained *list);
t_chained		*rotate_both_printless(t_chained *list1, t_chained *list2);

//Bonus Utils

t_strchained	*new_back_node_str(t_strchained *list, char *str);
t_strchained	*remove_back_node_str(t_strchained *list);
int				input_is_correct(t_strchained *input);
int				compare_with_valids(char *str);
t_strchained	*get_stdin_cmds(void);
void			execute_sorting_command(t_data *push_swap, char *str);
void			apply_stdin_cmds(t_data *push_swap, t_strchained *input);
#endif
