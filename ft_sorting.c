/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:42:05 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/16 16:43:27 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sortingbig(t_list **stack_a, t_list **stack_b, int ac, int *arr)
{
	t_chun	*array;

	if (ac == 501)
	{
		array = ft_chun(arr, 10, ac);
		algo(stack_a, stack_b, array, 10);
	}
	else if (ac == 101)
	{
		array = ft_chun(arr, 4, ac);
		algo(stack_a, stack_b, array, 2);
	}
	else
	{
		array = ft_chun(arr, 1, ac);
		algo(stack_a, stack_b, array, 1);
	}
}

void	sorting(t_list **stack_a, t_list **stack_b, int ac, int *arr)
{
	if (checker(*stack_a) == true)
		return ;
	if (ac == 4)
		sort_three(stack_a);
	if (ac == 3)
		sort_two(stack_a);
	if (ac == 6)
		sort_five(stack_a, stack_b);
	if (ac == 5)
		sort_four(stack_a, stack_b);
	if (ac > 6)
		ft_sortingbig(stack_a, stack_b, ac, arr);
}
