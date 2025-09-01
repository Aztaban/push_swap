/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:30:50 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/02 00:12:08 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prefer_dir(int len, int pos, int fallback_dir)
{
	int	forward;
	int	backward;

	forward = pos;
	backward = len - pos;
	if (forward < backward)
		return (1);
	if (backward < forward)
		return (-1);
	return (fallback_dir);
}

static t_move	calc_move_cost(const t_stack *a, const t_stack *b, int a_index)
{
	t_move	move;
	int		cost_a;
	int		cost_b;

	move.index = a_index;
	move.pos_a = pos_in_stack(a, a_index);
	move.pos_b = find_insert_pos_b(b, a_index);
	move.dir_a = prefer_dir(a->size, move.pos_a, 1);
	move.dir_b = prefer_dir(b->size, move.pos_b, move.dir_a);
	if (rot_cost(b->size, move.pos_b) == b->size - rot_cost(b->size, move.pos_b)
		&& move.dir_b != move.dir_a)
		move.dir_b = move.dir_a;
	cost_a = rot_cost(a->size, move.pos_a);
	cost_b = rot_cost(b->size, move.pos_b);
	if (move.dir_a != 0 && move.dir_a == move.dir_b)
	{
		if (cost_a > cost_b)
			move.cost = cost_a;
		else
			move.cost = cost_b;
	}
	else
		move.cost = cost_a + cost_b;
	return (move);
}

static int	better_choice(const t_move *best, const t_move *cur, int a_len)
{
	int	best_a;
	int	cur_a;

	if (cur->cost < best->cost)
		return (1);
	if (cur->cost > best->cost)
		return (0);
	best_a = rot_cost(a_len, best->pos_a);
	cur_a = rot_cost(a_len, cur->pos_a);
	if (cur_a < best_a)
		return (1);
	return (0);
}

t_move	find_best_move(const t_stack *a, const t_stack *b)
{
	t_node	*current;
	t_move	best_move;
	t_move	temp_move;
	int		a_len;

	if (!a || !a->head)
		return ((t_move){0});
	a_len = a->size;
	current = a->head;
	best_move = calc_move_cost(a, b, a->head->index);
	if (best_move.cost <= 2)
		return (best_move);
	current = current->next;
	while (current)
	{
		temp_move = calc_move_cost(a, b, current->index);
		if (better_choice(&best_move, &temp_move, a_len))
		{
			best_move = temp_move;
			if (best_move.cost <= 1)
				return (best_move);
		}
		current = current->next;
	}
	return (best_move);
}
