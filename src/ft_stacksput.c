/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:08:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 12:53:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stacksput(t_dblst *stack_a, t_dblst *stack_b)
{
	t_dbnode	*it_a;
	t_dbnode	*it_b;

	it_a = stack_a->head;
	it_b = stack_b->head;
	ft_printf("%16s%15s\n", "|a|", "|b|");
	while (it_a || it_b)
	{
		if (it_a && it_b)
			ft_printf("%15d%15d\n", *(int *)it_a->data->content,
				*(int *)it_b->data->content);
		else if (it_a)
			ft_printf("%15d\n", *(int *)it_a->data->content);
		else if (it_b)
			ft_printf("%30d\n", *(int *)it_b->data->content);
		if (it_a && (it_a = it_a->next) == stack_a->head)
			it_a = NULL;
		if (it_b && (it_b = it_b->next) == stack_b->head)
			it_b = NULL;
	}
}
