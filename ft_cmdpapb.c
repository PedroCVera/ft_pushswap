/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdpapb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:48:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/17 15:06:32 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **src, t_list **dest, int opt)
{
	t_list	*cursor_src;
	t_list	*cursor_dest;
	t_list	*temp;

	cursor_src = *src;
	if (!dest)
	{
		*dest = *src;
		cursor_dest = *dest;
		*src = cursor_src->next;
		cursor_dest->next = NULL;
	}
	else
	{
		cursor_dest = *dest;
		temp = cursor_src->next;
		cursor_src = *src;
		cursor_src->next = *dest;
		*src = temp;
		*dest = cursor_src;
	}
	if (opt == 1)
		write(1, "pb\n", 3);
	if (opt == 2)
		write(1, "pa\n", 3);
}
