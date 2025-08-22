/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:56:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/22 19:51:44 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *a = create_stack();
	t_stack *b = create_stack();

	push_front(a, 5);
	push_front(a, 3);
	push_front(a, 1);
	
	push_front(b, 1);
	push_front(b, 3);
	push_front(b, 5);

	print_stack("a", a);
	print_stack("b", b);

	rrr(a, b);

	print_stack("a", a);
	print_stack("b", b);

	rra(a);

	print_stack("a", a);
	print_stack("b", b);

	rrb(b);

	print_stack("a", a);
	print_stack("b", b);

	return (0);
}