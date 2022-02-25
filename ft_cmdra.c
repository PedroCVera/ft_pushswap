/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:54:36 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/17 15:05:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_ab(t_list **stack, int opt)
{
	t_list	*cursor1;
	t_list	*cursor2;

	if (stack == NULL)
		return ;
	if (ft_lstsize(*stack) != 1)
	{
		cursor2 = *stack;
		cursor1 = ft_lstlast(*stack);
		*stack = (*stack)->next;
		cursor2->next = NULL;
		cursor1->next = cursor2;
	}
	if (opt == 1)
		write(1, "ra\n", 3);
	if (opt == 2)
		write(1, "rb\n", 3);
}

void	rotate(t_list **stack_a, t_list **stack_b)
{
	rotate_ab(stack_a, 3);
	rotate_ab(stack_b, 3);
	write(1, "rr\n", 3);
}
