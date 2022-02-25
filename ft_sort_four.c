/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:26:24 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/10 10:32:54 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	put_smaller_four(t_list **stack_a, t_list **stack_b, int counter)
{
	if (counter > 1)
	{
		counter = 4 - counter;
		while (counter)
		{
			rev_rotate_ab(stack_a, 1);
			counter--;
		}
	}
	else
	{
		while (counter)
		{
			rotate_ab(stack_a, 1);
			counter--;
		}
	}
	push(stack_a, stack_b, 1);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	counter;

	counter = find_smaller(*stack_a);
	put_smaller_four(stack_a, stack_b, counter);
	if (checker(*stack_a) == true)
	{
		push(stack_b, stack_a, 2);
		return ;
	}
	sort_three(stack_a);
	push(stack_b, stack_a, 2);
}
