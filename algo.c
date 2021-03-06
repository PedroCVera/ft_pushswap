/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo   .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:20:13 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/24 15:20:14 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	algo(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt)
{
	if (!(*stack_a))
		return ;
	if (opt == 2)
		atob100(stack_a, stack_b, arr, opt);
	else if (opt == 10)
		atob500(stack_a, stack_b, arr, opt);
	else
		atobgeral(stack_a, stack_b);
}
