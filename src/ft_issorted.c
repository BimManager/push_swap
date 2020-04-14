/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:45:51 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/20 14:19:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_issorted(t_dblst *stack_a, t_dblst *stack_b)
{
	if (!stack_b)
		return (ft_dblst_issorted(stack_a, &intcmp, 1));
	return (ft_dblst_issorted(stack_a, &intcmp, 1) && !stack_b->head);
}
