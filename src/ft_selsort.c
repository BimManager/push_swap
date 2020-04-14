/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:55:50 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 17:48:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rxcalc(t_dblst *stack, int key, int *rx, int *rrx)
{
	t_dbnode	*it;

	*rx = 0;
	*rrx = 0;
	it = stack->head;
	if (*(int *)it->data->content == key)
		return ;
	while ((it = it->next) != stack->head && ++*rx)
		if (*(int *)it->data->content == key)
			break ;
	it = stack->head;
	while ((it = it->prev) != stack->head && ++*rrx)
		if (*(int *)it->data->content == key)
			break ;
}

static void	rxexec(t_dblst *stack_a, t_dblst *stack_b)
{
	static int	key;
	int			rx;
	int			rrx;

	rxcalc(stack_a, key, &rx, &rrx);
	if (rx <= rrx)
		while (rx--)
			ra(stack_a, stack_b, 1);
	else
		while (rrx--)
			rra(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	++key;
}

void		ft_selsort(t_dblst *stack_a, t_dblst *stack_b)
{
	while (!ft_issorted(stack_a, stack_b))
	{
		while (!ft_dblst_issorted(stack_a, &intcmp, 1))
		{
			if (2 == stack_a->elems)
			{
				sa(stack_a, stack_b, 1);
				break ;
			}
			rxexec(stack_a, stack_b);
		}
		while (stack_b->head)
			pa(stack_a, stack_b, 1);
	}
}
