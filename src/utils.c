/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 03:32:20 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 22:35:16 by mjusta           ###   ########.fr       */
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

	if (!s)
		return (-1);
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
	if (len <= 0 || pos < 0)
		return (0);
	if (pos <= len / 2)
		return (pos);
	else
		return (len - pos);
}

int	rot_dir(int len, int pos)
{
	if (len <= 0 || pos < 0)
		return (0);
	if (pos <= len / 2)
		return (1);
	return (-1);
}

void	finalize_sort(t_stack *a, t_stack *b)
{
	int	pos_a;
	int	rotation;
	int	b_top_index;

	while (b->size > 0)
	{
		b_top_index = b->head->index;
		pos_a = find_insert_pos_a(a, b_top_index);
		if (pos_a <= a->size / 2)
		{
			rotation = pos_a;
			while (rotation-- > 0)
				ra(a);
		}
		else
		{
			rotation = a->size - pos_a;
			while (rotation-- > 0)
				rra(a);
		}
		pa(a, b);
	}
	align_stack(a);
}
