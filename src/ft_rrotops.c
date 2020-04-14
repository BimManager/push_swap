/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:16:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 16:17:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_b;
	if (!stack_a->head)
		return ;
	stack_a->head = stack_a->head->prev;
	if (echo)
		ft_printf("rra\n");
}

void	rrb(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_a;
	if (!stack_b->head)
		return ;
	stack_b->head = stack_b->head->prev;
	if (echo)
		ft_printf("rrb\n");
}

void	rrr(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	rra(stack_a, stack_b, 0);
	rrb(stack_a, stack_b, 0);
	if (echo)
		ft_printf("rrr\n");
}
