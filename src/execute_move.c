/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:40:44 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 23:08:30 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rot_count(int len, int pos, int dir)
{
	if (dir == 1)
		return (pos);
	return (len - pos);
}

static void	overlap_both(t_stack *a, t_stack *b, int dir, t_move *move)
{
	int	shared;

	if (move->count_a < move->count_b)
		shared = move->count_a;
	else
		shared = move->count_b;
	if (shared <= 0)
		return ;
	if (dir == 1)
		do_rr_both(a, b, shared);
	else
		do_rrr_both(a, b, shared);
	move->count_a -= shared;
	move->count_b -= shared;
}

void	execute_move(t_stack *a, t_stack *b, t_move move)
{
	move.count_a = rot_count(a->size, move.pos_a, move.dir_a);
	move.count_b = rot_count(b->size, move.pos_b, move.dir_b);
	if (move.dir_a != 0 && move.dir_a == move.dir_b)
		overlap_both(a, b, move.dir_a, &move);
	do_rot_a(a, move.dir_a, move.count_a);
	do_rot_b(b, move.dir_b, move.count_b);
	pb(a, b);
}
