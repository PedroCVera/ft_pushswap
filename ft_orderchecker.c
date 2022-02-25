/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orderchecker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:24:42 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/24 14:41:38 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	checker(t_list *stack_a)
{
	t_list	*cursor;

	if (!stack_a)
	{
		write(1, "\nNo stack_a\n", 12);
		return (false);
	}
	cursor = stack_a;
	while (cursor->next)
	{
		if (cursor->content > cursor->next->content)
			return (false);
		cursor = cursor->next;
	}
	return (true);
}
