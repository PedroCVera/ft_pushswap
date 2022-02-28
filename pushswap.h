/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:26:53 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/02/24 14:38:37 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_ch
{
	int	max;
	int	min;
	int	imin;
	int	imax;
}		t_chun;

typedef struct i_ch
{
	int	x1;
	int	x2;
}		t_index;

void	ft_lstview(t_list *stack_a, t_list *stack_b);
void	swap_ab(t_list **stack, int opt);
bool	checking(char **av, int ac);
bool	is_it_num(char *c);
bool	num_equal(char *str1, char *str2);
bool	is_it_equal(char **av, int ind);
bool	ft_errorsatoi(const char *str);
void	push(t_list **src, t_list **dest, int opt);
void	swap(t_list **stack_a, t_list **stack_b);
void	rotate_ab(t_list **stack, int opt);
void	rotate(t_list **stack_a, t_list **stack_b);
void	rev_rotate_ab(t_list **stack, int opt);
bool	checker(t_list *stack_a);
void	sorting(t_list **stack_a, t_list **stack_b, int ac, int *arr);
void	sort_three(t_list **stack_a);
int		three_helper(t_list *stack);
void	sort_two(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		find_smaller(t_list *stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
t_chun	*ft_chun(int *arr, int opt, int ac);
void	pushchunk(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt);
//void	bigboys(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt);
void	algo(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt);
void	atobgeral(t_list **stack_a, t_list **stack_b);
void	atob100(t_list **a, t_list **b, t_chun *arr, int opt);
int		ft_findbig(t_list *stack);
void	atobgeral21(t_list **stack_a, t_list **stack_b);
void	atob500(t_list **stack_a, t_list **stack_b, t_chun *arr, int opt);
t_index	*create_chun500(int opt);
int		help500(t_list **a, t_list **b, t_chun *r, t_index *i);

#endif
