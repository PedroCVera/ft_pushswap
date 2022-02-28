/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:24:45 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/25 12:24:46 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_index	*create_chun500(int opt)
{
	t_index	*arr;

	arr = (t_index *)malloc(opt * sizeof(t_index));
	if (!arr)
		return (0);
	return (arr);
}

int	help500(t_list **a, t_list **b, t_chun *r, t_index *i)
{
	if ((*a)->content <= r[i[0].x1].max && (*a)->content >= r[i[0].x1].min)
	{
		push(a, b, 1);
		rotate_ab(b, 2);
		return (1);
	}
	else if ((*a)->content <= r[i[0].x2].max && (*a)->content >= r[i[0].x2].min)
	{
		push(a, b, 1);
		return (1);
	}
	else
	{
		rotate_ab(a, 1);
		return (0);
	}
}

void	chunk500(t_list **a, t_list **b, t_chun *arr)
{
	int		ss;
	t_index	*ind;

	ind = create_chun500(1);
	ind[0].x1 = 4;
	ind[0].x2 = 5;
	while (ft_lstsize(*a) != 0)
	{
		ss = 99;
		while (ss >= 0)
		{
			if (help500(a, b, arr, ind) == 1)
				ss--;
		}
		ind[0].x1--;
		ind[0].x2++;
	}
}

void	atob500(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt)
{
	chunk500(stack_a, stack_b, arr);
	opt = 4;
	atobgeral21(stack_a, stack_b);
}
