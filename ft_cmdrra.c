/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdrra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:40:15 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/17 15:00:21 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate_ab(t_list **stack, int opt)
{
	t_list	*cursor1;
	t_list	*cursor2;

	if (stack == NULL)
		return ;
	if (ft_lstsize(*stack) != 1)
	{
		cursor2 = *stack;
		cursor1 = *stack;
		while (cursor1->next->next)
			cursor1 = cursor1->next;
		*stack = cursor1->next;
		cursor1->next->next = cursor2;
		cursor1->next = NULL;
	}
	if (opt == 1)
		write(1, "rra\n", 4);
	if (opt == 2)
		write(1, "rrb\n", 4);
}

void	rev_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_ab(stack_a, 3);
	rev_rotate_ab(stack_b, 3);
	write(1, "rrr\n", 4);
}
