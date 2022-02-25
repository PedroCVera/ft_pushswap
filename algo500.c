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
	t_index	*array;

	array = (t_index *)malloc(opt * sizeof(t_index));
	if (!array)
		return (0);
	return (array);
}

void	c2hun500(t_list **a, t_list **b, t_chun *arr)
{
	int	ss;

	ss = arr[2].imax - arr[2].imin;
	while (ss >= 0)
	{
		if ((*a)->content <= arr[2].max && (*a)->content >= arr[2].min)
		{
			push(a, b, 1);
			ss--;
		}
		else
			rotate_ab(a, 1);
	}
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
	int	ss;
	t_index *ind;

	ind = create_chun500(1);
	ind[0].x1 = 1;
	ind[0].x2 = 3;
	while (ft_lstsize(*a) != 0)
	{
		ss = arr[ind[0].x1].imax - arr[ind[0].x1].imin;
		ss = ss + (arr[ind[0].x2].imax - arr[ind[0].x2].imin) + 1;
		while (ss >= 0)
		{
			if (help500(a, b, arr, ind) == 1)
				ss--;
		}
		ind[0].x1 = 0;
		ind[0].x2 = 4;
	}
}

void	AtoB500(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt)
{
	c2hun500(stack_a, stack_b, arr);
	chunk500(stack_a, stack_b, arr);
	AtoBgeralBA(stack_a, stack_b, arr);
}