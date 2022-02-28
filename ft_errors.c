/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:56:37 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/10 15:30:47 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	is_it_num(char *c)
{
	int	ind;

	ind = 0;
	if ((*c == '-' || *c == '+') && ft_strlen(c) == 1)
		return (false);
	if (*c == '-' || *c == '+')
		c++;
	while (*c)
	{
		if (*c < 48 || *c > 57)
			return (false);
		c++;
	}
	return (true);
}

bool	num_equal(char *str1, char *str2)
{
	int	num1;
	int	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num1 - num2 == 0)
		return (false);
	else
		return (true);
}

bool	is_it_equal(char **av, int ind)
{
	int	jnd;

	jnd = ind - 1;
	while (jnd > 0)
	{
		if (num_equal(av[jnd], av[ind]) == false)
			return (false);
		jnd--;
	}
	return (true);
}

bool	checking(char **av, int ac)
{
	int	ind;

	ind = 1;
	while (ind < ac)
	{
		if (av[ind][0] == '\0')
			return (false);
		if (is_it_num(av[ind]) == false)
			return (false);
		if (is_it_equal(av, ind) == false)
			return (false);
		if (ft_errorsatoi(av[ind]) == false)
			return (false);
		ind++;
	}
	return (true);
}
