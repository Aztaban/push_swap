/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:56:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 03:28:21 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main sorting using optimized Turk algorithm.
 * Uses chunk pushing for better performance on large stacks.
 */
static void	turk_sort(t_stack *a, t_stack *b)
{
	t_move	move;

	/* Phase 1: Smart push to B using chunks */
	chunk_push_to_b(a, b);
	
	/* Phase 2: Sort remaining 3 in A */
	if (a->size == 3 && !is_sorted(a))
		sort_three(a);
	else if (a->size == 2 && !is_sorted(a))
		sa(a);
	
	/* Phase 3: Greedy pull back from B */
	while (b->size > 0)
	{
		move = find_best_move_ba(a, b);
		execute_move_ba(a, b, move);
	}
	
	/* Phase 4: Align minimum to top */
	align_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stacks(&a, &b, argc, argv);
	index_compress(a);
	
	if (is_sorted(a))
		return (free_stack(b), free_stack(a),EXIT_SUCCESS);
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else
		turk_sort(a, b);
	return (free_stack(b), free_stack(a),EXIT_SUCCESS);
}

/* int	main(int argc, char **argv)
{
	int i = 0;
	bool error = false;

	if (argc == 2)
		i = ft_atoi_safe(argv[1], &error);
	if (error)
		return (ft_printf("Not a valid number\n"), 0);
	return (ft_printf("Number is %i\n", i), 0);
} */

/* int	main(void)
{
	t_stack *a = create_stack();
	t_stack *b = create_stack();

	push_front(a, 5);
	push_front(a, 3);
	push_front(a, 1);
	
	push_front(b, 1);
	push_front(b, 3);

	print_stack("a", a);
	print_stack("b", b);

	pa(a, b);

	print_stack("a", a);
	print_stack("b", b);

	pa(a, b);

	print_stack("a", a);
	print_stack("b", b);

	pa(a, b);

	print_stack("a", a);
	print_stack("b", b);

	free_stack(a);
	free_stack(b);
	return (0);
} */