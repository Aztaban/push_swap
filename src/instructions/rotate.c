/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:59:41 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 01:00:14 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Performs a rotation on a stack.
 *
 * Moves the first (head) node of the stack to the end (tail).
 *
 * @param s Pointer to the stack to rotate.
 * @return true if the rotation was performed, false if stack has <2 elements.
 */
static bool	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return (false);
	first = s->head;
	second = first->next;
	first->next = NULL;
	s->tail->next = first;
	s->tail = first;
	s->head = second;
	return (true);
}

/**
 * @brief Rotate stack A (ra).
 */
void	ra(t_stack *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

/**
 * @brief Rotate stack B (rb).
 */
void	rb(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

/**
 * @brief Rotate both stacks A and B simultaneously (rr).
 */
void	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) | rotate(b))
		ft_printf("rr\n");
}
