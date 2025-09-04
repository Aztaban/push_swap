/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:56:54 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 14:39:57 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * If the stack has only two elements, the tail is updated.
 *
 * @param s Pointer to the stack.
 * @return true if swap was performed, false if the stack has <2 elements.
 */
static bool	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return (false);
	first = s->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->head = second;
	if (s->size == 2)
		s->tail = first;
	return (true);
}

/**
 * @brief Swap the first two elements of stack A (sa).
 */
void	ch_sa(t_stack *a)
{
	swap(a);
}

/**
 * @brief Swap the first two elements of stack B (sb).
 */
void	ch_sb(t_stack *b)
{
	swap(b);
}

/**
 * @brief Swap the first two elements of both stacks A and B (ss).
 */
void	ch_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
