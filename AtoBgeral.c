/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AtoBgeral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:43:45 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/25 11:43:50 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_findbig(t_list *stack)
{
	t_list	*cursor;
	t_list	*biggie;
	int		counter;

	counter = 0;
	cursor = stack;
	biggie = stack;
	while (cursor)
	{
		if (biggie->content < cursor->content)
			biggie = cursor;
		cursor = cursor->next;
	}
	cursor = stack;
	while (cursor != biggie)
	{
		cursor = cursor->next;
		counter++;
	}
	return (counter);
}

void	AtoBgeralBA(t_list **stack_a, t_list **stack_b, t_chun *arr)
{
	int	counter;

	while (ft_lstsize(*stack_b) != 0)
	{
		counter = ft_findbig(*stack_b);
		if (ft_findbig(*stack_b) > (ft_lstsize(*stack_b) / 2))
		{
			counter = ft_lstsize(*stack_b) - counter;
			while (counter)
			{
				rev_rotate_ab(stack_b, 2);
				counter--;
			}
		}
		else
		{
			while (counter)
			{
				rotate_ab(stack_b, 2);
				counter--;
			}
		}
	push(stack_b, stack_a, 2);
	}
}

void	AtoBgeralAB(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) != 0)
		push(stack_a, stack_b, 1);
}

void	AtoBgeral(t_list **stack_a, t_list **stack_b, t_chun *arr)
{
	AtoBgeralAB(stack_a, stack_b);
	AtoBgeralBA(stack_a, stack_b, arr);
}