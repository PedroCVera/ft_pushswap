/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:26:18 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/24 14:50:51 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*void	ft_lstview(t_list *stack_a, t_list *stack_b)
{
	write(1, "stack_a\n", 8);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	write(1, "stack_b\n", 8);
	while (stack_b)
	{
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}*/

int	*org_arr(int ac, int *arr)
{
	int	ind;
	int	jnd;
	int	help;

	ind = 1;
	while (ind != 0)
	{
		jnd = 0;
		ind = 0;
		while (jnd < ac - 2)
		{
			if (arr[jnd] > arr[jnd + 1])
			{
				help = arr[jnd];
				arr[jnd] = arr[jnd + 1];
				arr[jnd + 1] = help;
				ind = 1;
			}
			jnd++;
		}
	}
	return (arr);
}

int	*create_arr(int ac, char *av[])
{
	int	*arr;
	int	ind;

	ind = 0;
	arr = (int *)malloc(ac * sizeof(int));
	if (!arr)
		return (0);
	while (ind < ac - 1)
	{
		arr[ind] = ft_atoi(av[ind + 1]);
		ind++;
	}
	arr = org_arr(ac, arr);
	ind = 0;
	return (arr);
}

void	put_in_stack(t_list **stack_a, char *av[], int ac)
{
	int	ind;

	ind = 1;
	while (ind < ac)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[ind])));
		ind++;
	}
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	if (checking (av, ac) == false)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	put_in_stack(&stack_a, av, ac);
	arr = create_arr(ac, av);
	sorting(&stack_a, &stack_b, ac, arr);
	return (0);
}
