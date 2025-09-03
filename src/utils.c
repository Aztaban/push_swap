/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 03:32:20 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 04:01:30 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if a stack is sorted in ascending order based on index.
 * 
 * @param s The stack to check.
 * @return true if sorted, false otherwise.
 */
bool	is_sorted(const t_stack *s)
{
	t_node	*current;

	if (!s || s->size <= 1)
		return (true);
	current = s->head;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (false);
		current = current->next;
	}
	return (true);
}

/**
 * @brief Find the position of a node with the given index in a stack.
 * 
 * @param s The stack to search.
 * @param index The target index to find.
 * @return The position of the index, or -1 if not found.
 */
int	pos_in_stack(const t_stack *s, int index)
{
	t_node	*current;
	int		position;

	if (!s)
		return (-1);
	current = s->head;
	position = 0;
	while (current)
	{
		if (current->index == index)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

/**
 * @brief Calculate the minimal rotation cost to bring an element to the top.
 * 
 * @param len The total number of elements in the stack.
 * @param pos The current position of the element.
 * @return Number of operations needed.
 */
int	rot_cost(int len, int pos)
{
	if (len <= 0 || pos < 0)
		return (0);
	if (pos <= len / 2)
		return (pos);
	else
		return (len - pos);
}

/**
 * @brief Determine rotation direction for minimal cost.
 * 
 * @param len The total number of elements in the stack.
 * @param pos The current position of the element.
 * @return 1 for rotate (ra/rb), -1 for reverse rotate (rra/rrb), 0 for invalid.
 */
int	rot_dir(int len, int pos)
{
	if (len <= 0 || pos < 0)
		return (0);
	if (pos <= len / 2)
		return (1);
	return (-1);
}
