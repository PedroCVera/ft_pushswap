/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:53:41 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/08 18:08:28 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	three_helper(t_list *stack)
{
	int	p1;
	int	p2;
	int	p3;

	p1 = stack->content;
	p2 = stack->next->content;
	p3 = stack->next->next->content;
	if (p1 > p2)
	{
		if (p1 > p3)
			return (1);
		if (p3 > p1)
			return (3);
	}
	if (p2 > p3)
		return (2);
	if (p3 > p1)
		return (3);
	return (0);
}

void	sort_three(t_list **stack_a)
{
	int	ind;

	if (checker(*stack_a) == true)
		return ;
	ind = three_helper(*stack_a);
	if (ind == 1)
	{
		rotate_ab(stack_a, 1);
		if (checker(*stack_a) == true)
			return ;
	}
	if (ind == 2)
	{
		rev_rotate_ab(stack_a, 1);
		if (checker(*stack_a) == true)
			return ;
	}
	swap_ab(stack_a, 1);
}
