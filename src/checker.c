/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3025/09/02 22:12:04 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 00:05:41 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec_instruction(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "rra", 4))
		rra(a);
	else if (!ft_strncmp(op, "rrb", 4))
		rrb(b);
	else if (!ft_strncmp(op, "rrr", 4))
		rrr(a, b);
	else if (!ft_strncmp(op, "sa", 3))
		sa(a);
	else if (!ft_strncmp(op, "sb", 3))
		sb(b);
	else if (!ft_strncmp(op, "ss", 3))
		ss(a, b);
	else if (!ft_strncmp(op, "pa", 3))
		pa(a, b);
	else if (!ft_strncmp(op, "pb", 3))
		pb(a, b);
	else if (!ft_strncmp(op, "ra", 3))
		ra(a);
	else if (!ft_strncmp(op, "rb", 3))
		rb(b);
	else if (!ft_strncmp(op, "rr", 3))
		rr(a, b);
	else
		return (-1);
	return (0);
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

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
	print_result(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
} 
