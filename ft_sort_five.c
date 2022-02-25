/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:33:14 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/14 16:46:13 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smaller(t_list *stack_a)
{
	t_list	*cursor;
	t_list	*smaller;
	int		counter;

	counter = 0;
	cursor = stack_a;
	smaller = stack_a;
	while (cursor)
	{
		if (smaller->content > cursor->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	cursor = stack_a;
	while (cursor != smaller)
	{
		cursor = cursor->next;
		counter++;
	}
	return (counter);
}

void	put_smaller_b(t_list **stack_a, t_list **stack_b, int counter, int opt)
{
	if (counter > 2)
	{
		if (opt == 1)
			counter = ft_lstsize(*stack_a) - counter;
		else
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

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	counter;

	counter = find_smaller(*stack_a);
	put_smaller_b(stack_a, stack_b, counter, 1);
	if (checker(*stack_a) == true)
	{
		push(stack_b, stack_a, 2);
		return ;
	}
	counter = find_smaller(*stack_a);
	put_smaller_b(stack_a, stack_b, counter, 2);
	sort_three(stack_a);
	push(stack_b, stack_a, 2);
	push(stack_b, stack_a, 2);
}
