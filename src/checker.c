/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3025/09/02 22:12:04 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 23:28:54 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Executes one instruction on the given stacks.
 * 
 * Returns 0 if successful, -1 if the instruction is invalid.
 */
static int	exec_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (!ft_strncmp(instruction, "rra", 4))
		ch_rra(a);
	else if (!ft_strncmp(instruction, "rrb", 4))
		ch_rrb(b);
	else if (!ft_strncmp(instruction, "rrr", 4))
		ch_rrr(a, b);
	else if (!ft_strncmp(instruction, "sa", 3))
		ch_sa(a);
	else if (!ft_strncmp(instruction, "sb", 3))
		ch_sb(b);
	else if (!ft_strncmp(instruction, "ss", 3))
		ch_ss(a, b);
	else if (!ft_strncmp(instruction, "pa", 3))
		ch_pa(a, b);
	else if (!ft_strncmp(instruction, "pb", 3))
		ch_pb(a, b);
	else if (!ft_strncmp(instruction, "ra", 3))
		ch_ra(a);
	else if (!ft_strncmp(instruction, "rb", 3))
		ch_rb(b);
	else if (!ft_strncmp(instruction, "rr", 3))
		ch_rr(a, b);
	else
		return (-1);
	return (0);
}

/**
 * @brief Prints "OK" if stack a is sorted and stack b is empty,
 * otherwise prints "KO".
 */
static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

/**
 * @brief Reads instructions from stdin and executes them.
 * 
 * Returns 0 if all instructions are valid, 1 if an error occurs.
 */
static int	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	char	*tmp;

	line = get_next_line(0);
	while (line)
	{
		tmp = ft_strtrim(line, "\n");
		free(line);
		if (!tmp)
			return (1);
		if (exec_instruction(a, b, tmp) == -1)
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		line = get_next_line(0);
	}
	return (0);
}

/**
 * @brief Entry point of the checker program.
 * Initializes stacks, processes instructions, and prints the result.
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stacks(&a, &b, argc, argv);
	if (process_instructions(a, b) != 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	
	
	return (print_result(a, b), free_stack(a), free_stack(b), 0);
}
