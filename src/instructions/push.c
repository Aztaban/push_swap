/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:58:48 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 01:07:44 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Transfers the top element from the source stack to the destination 
 *        stack.
 *
 * This function moves the head node from `src` to the front of `dst`,
 * adjusting both stacks' head pointers and sizes accordingly.
 *
 * @param dst The destination stack to receive the node.
 * @param src The source stack to lose its top node.
 * @return true if a node was transferred, false if the source was empty.
 */
static bool	push(t_stack *dst, t_stack *src)
{
	t_node	*new_src_head;
	t_node	*new_dst_head;

	if (src->size < 1)
		return (false);
	new_src_head = src->head->next;
	new_dst_head = src->head;
	new_dst_head->next = dst->head;
	dst->head = new_dst_head;
	src->head = new_src_head;
	dst->size++;
	src->size--;
	return (true);
}

/**
 * @brief Moves the top element from stack B to stack A.
 */
void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

/**
 * @brief Moves the top element from stack A to stack B.
 */
void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
