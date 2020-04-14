/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qlikesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 15:27:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushback(t_dblst *stack_a, t_dblst *stack_b, int key)
{
	t_dbnode	*it;
	int			rx;
	int			rrx;

	it = stack_b->head;
	rx = 0;
	while (*(int *)it->data->content != key && ++rx)
		it = it->next;
	it = stack_b->head;
	rrx = 0;
	while (*(int *)it->data->content != key && ++rrx)
		it = it->prev;
	if (rrx < rx)
		while (rrx--)
			rrb(stack_a, stack_b, 1);
	else
		while (rx--)
			rb(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

static int	chunkcalc(t_dblst *stack_a, int *step)
{
	if (200 < stack_a->elems)
		*step = 3;
	else if (50 <= stack_a->elems)
		*step = 2;
	else
		*step = 1;
	return (stack_a->elems >> *step);
}

static void	xsort(t_dblst *stack_a, t_dblst *stack_b)
{
	int	pivot;
	int	n;
	int	i;

	pivot = chunkcalc(stack_a, &i);
	n = pivot;
	while (stack_a->elems)
	{
		if (*(int *)stack_a->head->data->content < pivot)
		{
			pb(stack_a, stack_b, 1);
			--n;
			if (!n && (pivot += (stack_a->elems >> i) + (i >= 1 ? 1 : 0)))
				n = (stack_a->elems >> i) + (i >= 1 ? 1 : 0);
		}
		else if (*(int *)stack_a->head->data->content >= pivot)
		{
			if (*(int *)stack_a->head->prev->data->content < pivot)
				rra(stack_a, stack_b, 1);
			else
				while (*(int *)stack_a->head->data->content >= pivot)
					ra(stack_a, stack_b, 1);
		}
	}
}

void		ft_qlikesort(t_dblst *stack_a, t_dblst *stack_b)
{
	int		key;

	key = stack_a->elems;
	while (!ft_issorted(stack_a, stack_b))
	{
		xsort(stack_a, stack_b);
		while (stack_b->head)
			pushback(stack_a, stack_b, --key);
	}
}
