/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:13:52 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 16:17:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ra(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_b;
	if (!stack_a->head)
		return ;
	stack_a->head = stack_a->head->next;
	if (echo)
		ft_printf("ra\n");
}

void		rb(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_a;
	if (!stack_b->head)
		return ;
	stack_b->head = stack_b->head->next;
	if (echo)
		ft_printf("rb\n");
}

void		rr(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	ra(stack_a, stack_b, 0);
	rb(stack_a, stack_b, 0);
	if (echo)
		ft_printf("rr\n");
}
