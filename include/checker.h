/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:50 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/04 14:42:56 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"

void	ch_pa(t_stack *a, t_stack *b);
void	ch_pb(t_stack *a, t_stack *b);

void	ch_rra(t_stack *a);
void	ch_rrb(t_stack *b);
void	ch_rrr(t_stack *a, t_stack *b);

void	ch_ra(t_stack *a);
void	ch_rb(t_stack *b);
void	ch_rr(t_stack *a, t_stack *b);

void	ch_sa(t_stack *a);
void	ch_sb(t_stack *b);
void	ch_ss(t_stack *a, t_stack *b);

#endif