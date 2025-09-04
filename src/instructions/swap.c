/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:56:54 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/05 00:07:25 by mjusta           ###   ########.fr       */
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
 * @brief Swap the first two elements of stack A (sa) and print instruction.
 */
void	sa(t_stack *a, bool print)
{
	if (swap(a) && print)
		ft_printf("sa\n");
}

/**
 * @brief Swap the first two elements of stack B (sb) and print instruction.
 */
void	sb(t_stack *b, bool print)
{
	if (swap(b) && print)
		ft_printf("sb\n");
}

/**
 * @brief Swap the first two elements of both stacks A and B (ss)
 * and print instruction.
 */
void	ss(t_stack *a, t_stack *b, bool print)
{
	if ((swap(a) | swap(b)) && print)
		ft_printf("ss\n");
}
