/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:33:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/24 13:54:41 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	threesort(t_dblst *stack_a, t_dblst *stack_b)
{
	int	diff;

	if (ft_issorted(stack_a, stack_b))
		return ;
	diff = *(int *)stack_a->head->data->content -
		*(int *)stack_a->head->next->data->content;
	if (2 == diff)
		ra(stack_a, stack_b, 1);
	else if (-2 == diff)
	{
		rra(stack_a, stack_b, 1);
		sa(stack_a, stack_b, 1);
	}
	else if (1 == diff)
		sa(stack_a, stack_b, 1);
	else if (-1 == diff)
		rra(stack_a, stack_b, 1);
	if (!ft_dblst_issorted(stack_a, &intcmp, 1))
		rra(stack_a, stack_b, 1);
}

void		ft_sort(t_dblst *stack_a)
{
	t_dblst	*stack_b;

	ft_presort(stack_a);
	stack_b = ft_dblstnew();
	if (3 == stack_a->elems)
		threesort(stack_a, stack_b);
	else if (stack_a->elems <= 10)
		ft_selsort(stack_a, stack_b);
	else
		ft_qlikesort(stack_a, stack_b);
	ft_dblstdel(&stack_a, &intfree);
	ft_dblstdel(&stack_b, &intfree);
}
