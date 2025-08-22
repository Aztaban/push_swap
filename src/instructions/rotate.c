/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:59:41 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/22 16:30:00 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stack *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) | rotate(b))
		ft_printf("rr\n");
}
