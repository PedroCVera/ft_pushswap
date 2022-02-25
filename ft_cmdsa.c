/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:27:04 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/10 15:31:24 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_ab(t_list **stack, int opt)
{
	t_list	*cursor;

	cursor = *stack;
	*stack = (*stack)->next;
	cursor->next = (*stack)->next;
	(*stack)->next = cursor;
	if (opt == 1)
		write(1, "sa\n", 3);
	if (opt == 2)
		write(1, "sb\n", 3);
}

void	swap(t_list **stack_a, t_list **stack_b)
{
	swap_ab(stack_a, 3);
	swap_ab(stack_b, 3);
	write(1, "ss\n", 3);
}
