/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:56:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 23:58:52 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point of the push_swap program.
 */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.size = 0;
	a.head = NULL;
	a.tail = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!parse_args(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_stack(&a);
		exit(EXIT_FAILURE);
	}
	index_compress(&a);
	if (is_sorted(&a))
		return (free_stack(&a), EXIT_SUCCESS);
	if (a.size <= 5)
		sort_small(&a, &b);
	else
		turk_sort(&a, &b);
	return (free_stack(&b), free_stack(&a), EXIT_SUCCESS);
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
