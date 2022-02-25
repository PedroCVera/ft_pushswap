/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:09:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/24 14:37:11 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_chun	*create_chun(int opt)
{
	t_chun	*array;

	array = (t_chun *)malloc(opt * sizeof(t_chun));
	if (!array)
		return (0);
	return (array);
}

t_chun	*chun100(int *arr)
{
	t_chun	*array;

	array = create_chun(2);
	array[0].min = arr[0];
	array[0].max = arr[49];
	array[1].min = arr[50];
	array[1].max = arr[99];
	array[0].imin = 0;
	array[0].imax = 49;
	array[1].imin = 50;
	array[1].imax = 99;
	return (array);
}

t_chun	*chun500(int *arr)
{
	t_chun	*array;
	int		ind;
	int		jnd;
	int		hnd;

	hnd = 99;
	jnd = 0;
	array = create_chun(5);
	ind = 0;
	while (ind < 6)
	{
		array[ind].min = arr[jnd];
		array[ind].max = arr[hnd];
		array[ind].imin = jnd;
		array[ind].imax = hnd;
		ind++;
		jnd = jnd + 100;
		hnd = hnd + 100;
	}
	return (array);
}

t_chun	*chunchun(int *arr, int ac)
{
	t_chun	*array;

	array = create_chun(1);
	array[0].min = arr[0];
	array[0].max = arr[ac - 1];
	array[0].imin = 0;
	array[0].imax = ac - 1;
	return (array);
}

t_chun	*ft_chun(int *arr, int opt, int ac)
{
	t_chun	*array;

	if (opt == 2)
		array = chun100(arr);
	else if (opt == 5)
		array = chun500(arr);
	else
		array = chunchun(arr, ac);
	return (array);
}