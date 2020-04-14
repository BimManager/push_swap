/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:15:59 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 16:08:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	intfree(void *pint, size_t size)
{
	if (size)
		free(pint);
}

int		intcmp(const void *pa, const void *pb)
{
	if (*(int *)pa == *(int *)pb)
		return (0);
	else if (*(int *)pa > *(int *)pb)
		return (1);
	else
		return (-1);
}

void	strfree(void *str, size_t size)
{
	if (size)
		free(str);
}

int		nodecmp(t_dbnode *n1, t_dbnode *n2,
			int (*cmp)(const void *, const void *))
{
	return (cmp(n1->data->content, n2->data->content));
}
