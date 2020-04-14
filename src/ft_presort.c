/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:11:29 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/20 14:55:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	binsrch(const int *arr, size_t n, int k)
{
	size_t	i;

	i = n >> 1;
	if (!n)
		return (-1);
	else if (k == arr[i])
		return (i);
	else if (k < arr[i])
		return (binsrch(arr, i, k));
	else
		return (i + 1 + binsrch(arr + i + 1, n - i - 1, k));
}

static void	replace(t_dblst *stack_a, const int *arr, size_t n)
{
	t_dbnode	*it;

	it = stack_a->head;
	*(int *)it->data->content = binsrch(arr, n, *(int *)it->data->content);
	while ((it = it->next) != stack_a->head)
		*(int *)it->data->content = binsrch(arr, n, *(int *)it->data->content);
}

void		ft_presort(t_dblst *stack_a)
{
	int			*arr;
	t_dbnode	*it;
	int			i;

	arr = malloc(stack_a->elems * sizeof(int));
	it = stack_a->head;
	i = 0;
	ft_memcpy(&arr[i++], it->data->content, sizeof(int));
	while ((it = it->next) != stack_a->head)
		ft_memcpy(&arr[i++], it->data->content, sizeof(int));
	ft_qsort(arr, i, sizeof(int), &intcmp);
	replace(stack_a, arr, stack_a->elems);
	free(arr);
}
