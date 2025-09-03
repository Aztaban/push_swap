/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:29 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 03:01:28 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find position for element between two values.
 * Returns position where element should be inserted.
 */
static int	find_slot_position(const t_stack *a, int b_idx)
{
	t_node	*cur;
	t_node	*nxt;
	int		pos;

	cur = a->head;
	pos = 0;
	while (cur)
	{
		nxt = cur->next ? cur->next : a->head;
		/* Found the slot between cur and nxt */
		if (cur->index < b_idx && b_idx < nxt->index)
		{
			if (pos + 1 >= a->size)
				return (0);
			return (pos + 1);
		}
		cur = cur->next;
		pos++;
	}
	return (0);
}

/**
 * @brief Find where in A to insert element from B.
 * Handles edge cases for min/max values efficiently.
 */
int	find_insert_pos_a(const t_stack *a, int b_idx)
{
	int	min_idx;
	int	max_idx;

	if (!a || a->size == 0)
		return (0);
	
	/* Get min and max only once */
	min_idx = get_min_index(a);
	max_idx = get_max_index(a);
	
	/* Element is outside range - goes above minimum */
	if (b_idx < min_idx || b_idx > max_idx)
		return (pos_in_stack(a, min_idx));
	
	/* Element fits between existing values */
	return (find_slot_position(a, b_idx));
}
