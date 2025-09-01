/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:07:28 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 23:25:38 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(const t_stack *s)
{
	t_node	*current;
	int		min;

	if (!s || s->size == 0)
		return (-1);
	current = s->head;
	min = current->index;
	current = current->next;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	get_max_index(const t_stack *s)
{
	t_node	*current;
	int		max;

	if (!s || s->size == 0)
		return (-1);
	current = s->head;
	max = current->index;
	current = current->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static int	find_between_nodes(const t_stack *b, int a_index)
{
	t_node	*current;
	t_node	*next;
	int		i;

	current = b->head;
	i = 0;
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = b->head;
		if (current->index > a_index && a_index > next->index)
		{
			if (i + 1 == b->size)
				return (0);
			return (i + 1);
		}
		current = current->next;
		i++;
	}
	return (0);
}

int	find_insert_pos_b(const t_stack *b, int a_index)
{
	int	bmin;
	int	bmax;
	int	pos_max;

	if (!b || b->size == 0)
		return (0);
	if (b->size == 1)
	{
		if (a_index > b->head->index)
			return (0);
		else
			return (1);
	}
	bmin = get_min_index(b);
	bmax = get_max_index(b);
	if (a_index > bmax || a_index < bmin)
	{
		pos_max = pos_in_stack(b, bmax);
		if (pos_max < 0 || (pos_max + 1) == b->size)
			return (0);
		return (pos_max + 1);
	}
	return (find_between_nodes(b, a_index));
}
