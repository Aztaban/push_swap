/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:55:17 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/25 14:45:57 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(const char *s)
{
	if (!s || !*s)
		return (false);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit)
			return (false);
		s++;
	}
	return (true);
}

int	ft_atoi_safe(const char *str, bool *err)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*err = false;
	if (*str == '+' || *str == '-')
		if(*str++ == '-')
			sign = -1;
	while (*str)
	{
		
	}
}