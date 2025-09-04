/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:40:44 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 18:27:48 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculate the number of rotations needed.
 *
 * @param len Stack size.
 * @param pos Position of the target element.
 * @param dir Direction (1 for rotate, -1 for reverse rotate, 0 for none).
 * @return The number of rotations required.
 */
static int	rot_count(int len, int pos, int dir)
{
	if (dir == 1)
		return (pos);
	if (dir == -1)
		return (len - pos);
	return (0);
}

/**
 * @brief Perform simultaneous rotations on both stacks when possible.
 *
 * If both stacks need rotations in the same direction, overlap them
 * to minimize total moves. The shared rotations are executed first,
 * then the remaining rotations are handled separately.
 *
 * @param a Stack A.
 * @param b Stack B.
 * @param dir Direction (1 for rotate, -1 for reverse rotate).
 * @param move Move structure holding rotation counts for A and B.
 */
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

/**
 * @brief Execute the optimal move to push an element from B to A.
 *
 * This function calculates the rotation counts for both stacks,
 * overlaps rotations if both stacks rotate in the same direction,
 * performs the remaining rotations, and finally pushes the element
 * from B to A.
 */
void	execute_move_ba(t_stack *a, t_stack *b, t_move move)
{
	move.count_a = rot_count(a->size, move.pos_a, move.dir_a);
	move.count_b = rot_count(b->size, move.pos_b, move.dir_b);
	if (move.dir_a != 0 && move.dir_a == move.dir_b)
		overlap_both(a, b, move.dir_a, &move);
	do_rot_a(a, move.dir_a, move.count_a);
	do_rot_b(b, move.dir_b, move.count_b);
	pa(a, b);
}
