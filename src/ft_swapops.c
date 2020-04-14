/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:07:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 16:18:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		sa(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_b;
	if (!stack_a->head)
		return ;
	ft_swap(stack_a->head->data->content,
			stack_a->head->next->data->content, sizeof(t_data));
	if (echo)
		ft_printf("sa\n");
}

void		sb(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	(void)stack_a;
	if (!stack_b->head)
		return ;
	ft_swap(stack_b->head->data->content,
			stack_b->head->next->data->content, sizeof(t_data));
	if (echo)
		ft_printf("sb\n");
}

void		ss(t_dblst *stack_a, t_dblst *stack_b, int echo)
{
	sa(stack_a, stack_b, 0);
	sb(stack_a, stack_b, 0);
	if (echo)
		ft_printf("ss\n");
}
