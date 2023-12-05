/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:25:05 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/06 11:01:17 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare_with_valids(char *str)
{
	if (ft_strncmp(str, "pa", 3) && ft_strncmp(str, "pb", 3)
		&& ft_strncmp(str, "ra", 3) && ft_strncmp(str, "rb", 3)
		&& ft_strncmp(str, "rr", 3) && ft_strncmp(str, "rra", 4)
		&& ft_strncmp(str, "rrb", 4) && ft_strncmp(str, "rrr", 4)
		&& ft_strncmp(str, "sa", 3) && ft_strncmp(str, "sb", 3)
		&& ft_strncmp(str, "ss", 3) && str != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}

t_strchained	*get_stdin_cmds(void)
{
	t_strchained	*input;
	char			*buffer;
	char			*trimed;

	input = malloc(sizeof(t_strchained));
	if (!input)
		return (NULL);
	input->nb_elem = 0;
	buffer = ft_calloc(1, 1);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(STDIN_FILENO);
		if (buffer)
		{
			trimed = ft_strtrim(buffer, "\n");
			compare_with_valids(trimed);
			new_back_node_str(input, trimed);
			free(trimed);
		}
	}
	free(buffer);
	return (input);
}

void	execute_sorting_command(t_data *push_swap, char *str)
{
	if (str && ft_strncmp(str, "pa", 3) == 0)
		push_without_print(push_swap->b, push_swap->a);
	else if (str && ft_strncmp(str, "pb", 3) == 0)
		push_without_print(push_swap->a, push_swap->b);
	else if (str && ft_strncmp(str, "ra", 3) == 0)
		rotate_without_print(push_swap->a);
	else if (str && ft_strncmp(str, "rb", 3) == 0)
		rotate_without_print(push_swap->b);
	else if (str && ft_strncmp(str, "rr", 3) == 0)
		rotate_both_printless(push_swap->a, push_swap->b);
	else if (str && ft_strncmp(str, "rra", 3) == 0)
		reverse_without_print(push_swap->a);
	else if (str && ft_strncmp(str, "rrb", 3) == 0)
		reverse_without_print(push_swap->b);
	else if (str && ft_strncmp(str, "rrr", 3) == 0)
		reverse_both_printless(push_swap->a, push_swap->b);
	else if (str && ft_strncmp(str, "sa", 3) == 0)
		swap_without_print(push_swap->a);
	else if (str && ft_strncmp(str, "sb", 3) == 0)
		swap_without_print(push_swap->b);
	else if (str && ft_strncmp(str, "ss", 3) == 0)
		swap_both_without_print(push_swap->a, push_swap->b);
}

void	apply_stdin_cmds(t_data *push_swap, t_strchained *input)
{
	t_strnode	*temp;

	temp = input->start;
	while (temp)
	{
		execute_sorting_command(push_swap, temp->str);
		temp = temp->next;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data			*push_swap;
	t_strchained	*input;

	if (!av[1])
		return (0);
	push_swap = malloc(sizeof(*push_swap));
	if (!check_errors(av, ac))
		return (-1);
	get_data(push_swap, ac, av);
	input = get_stdin_cmds();
	if (input->nb_elem > 0)
		apply_stdin_cmds(push_swap, input);
	if (is_sorted(push_swap->a) && is_empty(push_swap->b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
