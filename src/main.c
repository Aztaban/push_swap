/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:56:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 18:47:14 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point of the push_swap program.
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stacks(&a, &b, argc, argv);
	index_compress(a);
	if (is_sorted(a))
		return (free_stack(b), free_stack(a), EXIT_SUCCESS);
	if (a->size <= 5)
		sort_small(a, b);
	else
		turk_sort(a, b);
	return (free_stack(b), free_stack(a), EXIT_SUCCESS);
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
