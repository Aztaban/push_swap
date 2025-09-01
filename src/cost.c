/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:30:50 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 17:49:08 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	calculate_move_cost(const t_stack *a, const t_stack *b, int a_index)
{
	t_move	move;
	int		cost_a;
	int		cost_b;

	move.index = a_index;
	move.pos_a = pos_in_stack(a, a_index);
	move.pos_b = find_insert_pos_b(b, a_index);
	move.dir_a = rot_dir(a->size, move.pos_a);
	move.dir_b = rot_dir(b->size, move.pos_b);
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

t_move	find_best_move(const t_stack *a, const t_stack *b)
{
	t_node	*current;
	t_move	best_move;
	t_move	temp_move;

	if (!a || !a->head)
		return ((t_move){0});
	current = a->head;
	best_move = calculate_move_cost(a, b, current->index);
	current = current->next;
	while (current)
	{
		temp_move = calculate_move_cost(a, b, current->index);
		if (temp_move.cost < best_move.cost)
			best_move = temp_move;
		current = current->next;
	}
	return (best_move);
}
