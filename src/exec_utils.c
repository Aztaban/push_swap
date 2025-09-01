/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:56:05 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 22:56:31 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_both(t_stack *a, t_stack *b, int times)
{
	while (times-- > 0)
		rr(a, b);
}

void	do_rrr_both(t_stack *a, t_stack *b, int times)
{
	while (times-- > 0)
		rrr(a, b);
}

void	do_rot_a(t_stack *a, int dir, int times)
{
	while (times-- > 0)
	{
		if (dir == 1)
			ra(a);
		else
			rra(a);
	}
}

void	do_rot_b(t_stack *b, int dir, int times)
{
	while (times-- > 0)
	{
		if (dir == 1)
			rb(b);
		else
			rrb(b);
	}
}
