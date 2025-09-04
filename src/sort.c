/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:17:10 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 19:04:02 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts exactly 3 elements in stack A.
 * Uses minimal moves based on all 6 possible permutations.
 */
static void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3 || is_sorted(a))
		return ;
	top = a->head->index;
	mid = a->head->next->index;
	bot = a->head->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

/**
 * @brief Pushes minimum element from A to B.
 * Uses optimal rotation direction.
 */
static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	position;
	int	direction;
	int	rotations;

	min_idx = get_min_index(a);
	position = pos_in_stack(a, min_idx);
	direction = rot_dir(a->size, position);
	rotations = rot_cost(a->size, position);
	do_rot_a(a, direction, rotations);
	pb(a, b);
}

/**
 * @brief Aligns stack A so minimum is at top.
 * Final step to ensure sorted order starts from index 0.
 */
static void	align_stack(t_stack *a)
{
	int	min_idx;
	int	position;
	int	direction;

	if (a->size <= 1)
		return ;
	min_idx = get_min_index(a);
	position = pos_in_stack(a, min_idx);
	if (position == 0)
		return ;
	direction = rot_dir(a->size, position);
	while (position != 0)
	{
		if (direction == 1)
			ra(a);
		else
			rra(a);
		position = pos_in_stack(a, min_idx);
	}
}

/**
 * @brief Sort small stacks (size ≤ 5) using push-swap optimized logic.
 * 
 * Moves the smallest elements from A to B until only 3 are left,
 * sorts the 3 elements in A, then reinserts elements from B back to A
 * using cost-based reinsertion. Finally, aligns A to have the smallest 
 * value at the top.
 * 
 * @param a Stack A (main stack)
 * @param b Stack B (auxiliary stack)
 */
void	sort_small(t_stack *a, t_stack *b)
{
	t_move	move;

	if (a->size <= 1)
		return ;
	if (a->size == 2)
		return (sa(a));
	if (a->size == 3)
		return (sort_three(a));
	while (a->size > 3 && !is_sorted(a))
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		move = find_best_move_ba(a, b);
		execute_move_ba(a, b, move);
	}
	align_stack(a);
}

/**
 * @brief Main sorting using optimized Turk algorithm.
 * Uses chunk pushing for better performance on large stacks.
 */
void	turk_sort(t_stack *a, t_stack *b)
{
	t_move	move;

	chunk_push_to_b(a, b);
	if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
	{
		move = find_best_move_ba(a, b);
		execute_move_ba(a, b, move);
	}
	align_stack(a);
}
