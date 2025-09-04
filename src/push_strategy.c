/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 03:02:12 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 17:14:22 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the optimal chunk size based on the total size of stack a.
 * Smaller stack sizes use smaller chunks, and larger stacks use bigger chunks.
 * 
 * @param total_size The total number of elements in stack a.
 * @return The chunk size to use for the push strategy.
 */
static int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (35);
	else if (total_size <= 500)
		return (50);
	else
		return (85);
}

/**
 * @brief Check whether a given index falls within the current chunk range.
 * 
 * @param index Index to check.
 * @param chunk_start Start of the chunk range (inclusive).
 * @param chunk_end End of the chunk range (exclusive).
 * @return 1 if the index is inside the chunk, otherwise 0.
 */
static bool	in_chunk(int index, int chunk_start, int chunk_end)
{
	return (index >= chunk_start && index < chunk_end);
}

/**
 * @brief Calculate the number of rotations needed to reach the next element
 * that belongs to the current chunk.
 * 
 * @param a Stack a.
 * @param chunk_start Start index of the current chunk.
 * @param chunk_end End index of the current chunk.
 * @return Minimum rotation cost to bring a chunk element to the top.
 */
static int	rotations_to_chunk(t_stack *a, int chunk_start, int chunk_end)
{
	t_node	*node;
	int		pos;
	int		min_rot;
	int		rot_cost_val;

	node = a->head;
	pos = 0;
	min_rot = a->size;
	while (node)
	{
		if (in_chunk(node->index, chunk_start, chunk_end))
		{
			rot_cost_val = rot_cost(a->size, pos);
			if (rot_cost_val < min_rot)
				min_rot = rot_cost_val;
		}
		node = node->next;
		pos++;
	}
	return (min_rot);
}

/**
 * @brief Push all elements in the current chunk from stack a to b.
 * Rotates a until a chunk element is on top, then pushes it.
 * If the pushed element is in the lower half, rotate b to balance it.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param c_start Start index of the current chunk.
 * @param c_end End index of the current chunk.
 */
static void	handle_chunk_push(t_stack *a, t_stack *b, int c_start, int c_end)
{
	int	mid;

	mid = a->size / 2;
	while (a->size > 3 && rotations_to_chunk(a, c_start, c_end) < a->size)
	{
		if (in_chunk(a->head->index, c_start, c_end))
		{
			pb(a, b);
			if (b->size > 1 && b->head->index < mid)
				rb(b);
		}
		else
			ra(a);
	}
}

/**
 * @brief Push elements from stack a to b using a chunked approach.
 * This reduces the number of operations by pushing groups of values
 * based on index ranges (chunks) instead of individually.
 * 
 * @param a Stack a to sort.
 * @param b Auxiliary stack b used for sorting.
 */
void	chunk_push_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	total;

	if (a->size <= 5)
		return ;
	total = a->size;
	chunk_size = get_chunk_size(total);
	chunk_start = 0;
	while (a->size > 3)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > total)
			chunk_end = total;
		handle_chunk_push(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end;
	}
}
