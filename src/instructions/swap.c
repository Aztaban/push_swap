/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:56:54 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/22 01:53:48 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}
void	sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}
void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) | swap(b))
		ft_printf("ss\n");
}