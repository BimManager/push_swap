/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:11:34 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 16:15:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	if (!stack_b->head)
		return ;
	ft_dblstcons(stack_a, ft_dblstpop(stack_b));
	if (echo)
		ft_printf("pa\n");
}

void	pb(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	if (!stack_a->head)
		return ;
	ft_dblstcons(stack_b, ft_dblstpop(stack_a));
	if (echo)
		ft_printf("pb\n");
}
