/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:01:01 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/05 00:04:41 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Performs a reverse rotation on a stack.
 *
 * Moves the last element of the stack to the front (head).
 *
 * @param s Pointer to the stack to rotate.
 * @return true if the operation was performed, false if the stack has <2 
 *         elements.
 */
static bool	reverse_rotate(t_stack *s)
{
	t_node	*new_head;
	t_node	*new_tail;

	if (s->size < 2)
		return (false);
	new_head = s->tail;
	new_tail = s->head;
	while (new_tail->next && new_tail->next != s->tail)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	new_head->next = s->head;
	s->head = new_head;
	s->tail = new_tail;
	return (true);
}

/**
 * @brief Reverse rotate stack A (rra) and print instruction.
 */
void	rra(t_stack *a, bool print)
{
	if (reverse_rotate(a) && print)
		ft_printf("rra\n");
}

/**
 * @brief Reverse rotate stack B (rrb) and print instruction..
 */
void	rrb(t_stack *b, bool print)
{
	if (reverse_rotate(b) && print)
		ft_printf("rrb\n");
}

/**
 * @brief Reverse rotate both stacks A and B (rrr) and print instruction.
 */
void	rrr(t_stack *a, t_stack *b, bool print)
{
	if ((reverse_rotate(a) | reverse_rotate(b)) && print)
		ft_printf("rrr\n");
}
