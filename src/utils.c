/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 03:32:20 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 03:55:08 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	pos_in_stack(const t_stack *s, int index)
{
	t_node	*current;
	int		position;

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

int	rot_cost(int len, int pos)
{
	if (pos <= len /2)
		return (pos);
	else
		return (len - pos);
}