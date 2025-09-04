/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:56:05 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/05 00:29:12 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotate both stacks forward ('rr') a given number of times.
 */
void	do_rr_both(t_stack *a, t_stack *b, int times)
{
	while (times-- > 0)
		rr(a, b, true);
}

/**
 * @brief Reverse rotate both stacks ('rrr') a given number of times.
 */
void	do_rrr_both(t_stack *a, t_stack *b, int times)
{
	while (times-- > 0)
		rrr(a, b, true);
}

/**
 * @brief Rotate stack A 'times' times in the given direction.
 * dir == 1 for ra (rotate up), dir == -1 for rra (rotate down).
 */
void	do_rot_a(t_stack *a, int dir, int times)
{
	while (times-- > 0)
	{
		if (dir == 1)
			ra(a, true);
		else
			rra(a, true);
	}
}

/**
 * @brief Rotate stack B 'times' times in the given direction.
 * dir == 1 for rb (rotate up), dir == -1 for rrb (rotate down).
 */
void	do_rot_b(t_stack *b, int dir, int times)
{
	while (times-- > 0)
	{
		if (dir == 1)
			rb(b, true);
		else
			rrb(b, true);
	}
}
