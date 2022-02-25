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

void	AtoB100(t_list **a, t_list **b, t_chun *arr, int opt)
{
	ab100(a, b, arr);
	AtoBgeralBA(a, b, arr);
}