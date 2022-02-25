/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:42:05 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/01 16:22:13 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_ispace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

bool	ft_errorsatoi(const char *str)
{
	int		sign;
	long	r;
	long	maxint;
	long	minint;

	minint = -2147483648;
	maxint = 2147483647;
	r = 0;
	sign = 1;
	while (ft_ispace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + *str - '0';
		str++;
	}
	if (r < minint || r > maxint)
		return (false);
	return (true);
}
