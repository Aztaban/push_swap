/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:56:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/30 00:05:56 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = create_stack();
	if (!a)
		return (EXIT_FAILURE);
	b = create_stack();
	if (!b)
		return (free_stack(a), EXIT_FAILURE);
	if (!parse_args(argc, argv, a))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (free_stack(a), free_stack(b), EXIT_FAILURE);
	}
	// should i check by indexes or the real value before indexing?
	index_compress(a);
	if (!is_sorted(a))
		// TODO: Here will be the sorting magic
	print_stack("Stack A", a);
	return (free_stack(a), free_stack(b), EXIT_SUCCESS);
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