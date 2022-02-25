/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:46:20 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/07 11:54:54 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_list **stack_a)
{
	if (!stack_a)
		return ;
	if (checker(*stack_a) == true)
		return ;
	swap_ab(stack_a, 1);
}
