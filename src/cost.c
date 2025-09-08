/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:30:50 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/08 22:37:16 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculate rotation cost for a position.
 * Returns minimum between forward and backward rotation.
 */
static int	min_rotation_cost(int size, int pos)
{
	int	forward;
	int	backward;

	forward = pos;
	backward = size - pos;
	if (forward < backward)
		return (forward);
	return (backward);
}

/**
 * @brief Determine best rotation direction.
 * 1 for forward (ra/rb), -1 for backward (rra/rrb).
 */
static int	best_rotation_dir(int size, int pos)
{
	int	forward;
	int	backward;

	forward = pos;
	backward = size - pos;
	if (forward <= backward)
		return (1);
	return (-1);
}

/**
 * @brief Calculate move cost from B to A.
 * Optimizes for same-direction rotations when possible.
 */
static t_move	calc_move_cost_ba(const t_stack *a, const t_stack *b, int b_idx)
{
	t_move	move;
	int		costa;
	int		costb;

	move.index = b_idx;
	move.pos_b = pos_in_stack(b, b_idx);
	move.pos_a = find_insert_pos_a(a, b_idx);
	costa = min_rotation_cost(a->size, move.pos_a);
	costb = min_rotation_cost(b->size, move.pos_b);
	move.dir_a = best_rotation_dir(a->size, move.pos_a);
	move.dir_b = best_rotation_dir(b->size, move.pos_b);
	if (move.dir_a == move.dir_b)
	{
		if (costa > costb)
			move.cost = costa;
		else
			move.cost = costb;
	}
	else
		move.cost = costa + costb;
	return (move);
}

/**
 * @brief Find the cheapest move from B to A.
 * Early exit for very cheap moves (cost <= 1).
 */
t_move	find_best_move_ba(const t_stack *a, const t_stack *b)
{
	t_node	*cur;
	t_move	best;
	t_move	tmp;

	ft_memset(&best, 0, sizeof(best));
	if (!b || !b->head)
		return (best);
	cur = b->head;
	best = calc_move_cost_ba(a, b, cur->index);
	if (best.cost <= 1)
		return (best);
	cur = cur->next;
	while (cur)
	{
		tmp = calc_move_cost_ba(a, b, cur->index);
		if (tmp.cost < best.cost)
		{
			best = tmp;
			if (best.cost <= 1)
				return (best);
		}
		cur = cur->next;
	}
	return (best);
}
