/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:17:10 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 23:59:34 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3)
		return ;
	top = a->head->index;
	mid = a->head->next->index;
	bot = a->head->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	align_stack(t_stack *a)
{
	int	min;
	int	pos;
	int	dir;

	min = get_min_index(a);
	pos = pos_in_stack(a, min);
	dir = rot_dir(a->size, pos);
	while (pos != 0)
	{
		if (dir == 1)
			ra(a);
		else
			rra(a);
		pos = pos_in_stack(a, min);
	}
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
