/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 03:02:12 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 03:02:19 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculate chunk size based on stack size.
 * Smaller chunks for smaller stacks, larger for bigger ones.
 */
static int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (20);
	else if (total_size <= 500)
		return (45);
	else
		return (65);
}

/**
 * @brief Check if index belongs to current chunk.
 */
static bool	in_chunk(int index, int chunk_start, int chunk_end)
{
	return (index >= chunk_start && index < chunk_end);
}

/**
 * @brief Count rotations needed to find next chunk element.
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
 * @brief Push elements to B using chunk strategy.
 * Pushes elements in chunks to reduce overall rotations.
 */
void	chunk_push_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	total;
	int	mid_point;

	if (a->size <= 5)
		return ;
	total = a->size;
	chunk_size = get_chunk_size(total);
	chunk_start = 0;
	mid_point = total / 2;
	
	while (a->size > 3)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > total)
			chunk_end = total;
		
		/* Push current chunk */
		while (a->size > 3 && rotations_to_chunk(a, chunk_start, chunk_end) < a->size)
		{
			if (in_chunk(a->head->index, chunk_start, chunk_end))
			{
				pb(a, b);
				/* Optimize B placement for elements near middle */
				if (b->size > 1 && b->head->index < mid_point && b->head->index < b->head->next->index)
					rb(b);
			}
			else
				ra(a);
		}
		chunk_start = chunk_end;
	}
}
