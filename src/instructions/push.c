/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:58:48 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/05 00:03:27 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/**
 * @brief Transfer the top element from src to the front of dst.
 *
 * Moves the head node from src to become the new head of dst, updating
 * both stacks' head pointers, tail pointers (when necessary), and sizes.
 *
 * Behavior & invariants:
 * 
 * - If dst was empty, the moved node becomes both head and tail of dst.
 * 
 * - If src becomes empty after the move, src->tail is set to NULL.
 * 
 * - Sizes are adjusted: dst->size++ and src->size--.
 *
 * @param dst Destination stack that will receive the node.
 * @param src Source stack that will lose its top node.
 * @return true if a node was transferred; false if src was empty.
 */
static bool	push(t_stack *dst, t_stack *src)
{
	t_node	*moved;

	if (src->size == 0)
		return (false);
	moved = src->head;
	src->head = moved->next;
	src->size--;
	if (src->size == 0)
		src->tail = NULL;
	if (dst->size == 0)
	{
		moved->next = NULL;
		dst->head = moved;
		dst->tail = moved;
	}
	else
	{
		moved->next = dst->head;
		dst->head = moved;
	}
	dst->size++;
	return (true);
}

/**
 * @brief Moves the top element from stack B to stack A 
 * and prints a message.
 */
void	pa(t_stack *a, t_stack *b, bool print)
{
	if (push(a, b) && print)
		ft_printf("pa\n");
}

/**
 * @brief Moves the top element from stack A to stack B
 * and prints a message.
 */
void	pb(t_stack *a, t_stack *b, bool print)
{
	if (push(b, a) && print)
		ft_printf("pb\n");
}
