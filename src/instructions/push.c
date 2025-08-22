/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:58:48 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/22 16:26:18 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack *dst, t_stack *src);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);