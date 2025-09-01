/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:40:44 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 17:32:52 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_stacks(t_stack *a, t_stack *b, t_move *m)
{
	while (m->pos_a > 0 && m->pos_b > 0)
	{
		if (m->dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		m->pos_a--;
		m->pos_b--;
	}
}

static void	rotate_stack_a(t_stack *a, int direction, int times)
{
	while (times-- > 0)
	{
		if (direction == 1)
			ra(a);
		else
			rra(a);
	}
}

static void	rotate_stack_b(t_stack *b, int direction, int times)
{
	while (times-- > 0)
	{
		if (direction == 1)
			rb(b);
		else
			rrb(b);
	}
}

void	execute_move(t_stack *a, t_stack *b, t_move move)
{
	if (move.dir_a == move.dir_b)
		rotate_both_stacks(a, b, &move);
	rotate_stack_a(a, move.dir_a, move.pos_a);
	rotate_stack_b(b, move.dir_b, move.pos_b);
	pb(a, b);
}
