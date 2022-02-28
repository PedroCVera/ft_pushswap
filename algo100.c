/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:01:42 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/25 12:01:44 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	num_chan(t_list **a, t_list **b, t_chun *arr)
{
	if (ft_lstsize(*a) == 0)
		return ;
	if ((*a)->content <= arr[0].max && (*a)->content >= arr[0].min)
	{
		push(a, b, 1);
		rotate_ab(b, 2);
	}
	else if ((*a)->content <= arr[1].max && (*a)->content >= arr[1].min)
	{
		push(a, b, 1);
	}
}

void	ab100(t_list **a, t_list **b, t_chun *arr)
{
	while (ft_lstsize(*a) != 0)
		num_chan(a, b, arr);
}

void	c4hun(t_list **a, t_list **b, t_chun *arr)
{
	int		ss;
	t_index	*ind;

	ind = create_chun500(1);
	ind[0].x1 = 1;
	ind[0].x2 = 2;
	while (ft_lstsize(*a) != 0)
	{
		ss = arr[ind[0].x1].imax - arr[ind[0].x1].imin;
		ss = ss + (arr[ind[0].x2].imax - arr[ind[0].x2].imin) + 1;
		while (ss >= 0)
		{
			if (help500(a, b, arr, ind) == 1)
				ss--;
		}
		ind[0].x1 = ind[0].x1 - 1;
		ind[0].x2 = ind[0].x2 + 1;
	}
}

void	atob100(t_list **a, t_list **b, t_chun *arr, int opt)
{
	c4hun(a, b, arr);
	opt = 4;
	atobgeral21(a, b);
}
