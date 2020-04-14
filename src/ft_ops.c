/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:09:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 19:19:13 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_opadd(t_trie *trie, const char *op, size_t addr)
{
	ft_trieadd(trie, op, ft_datanew(&addr, sizeof(void *)));
}

t_trie		*ft_opsetup(void)
{
	t_trie	*trie;

	trie = ft_trienew(NULL);
	ft_opadd(trie, "sa", (size_t)&sa);
	ft_opadd(trie, "sb", (size_t)&sb);
	ft_opadd(trie, "ss", (size_t)&ss);
	ft_opadd(trie, "pa", (size_t)&pa);
	ft_opadd(trie, "pb", (size_t)&pb);
	ft_opadd(trie, "ra", (size_t)&ra);
	ft_opadd(trie, "rb", (size_t)&rb);
	ft_opadd(trie, "rr", (size_t)&rr);
	ft_opadd(trie, "rra", (size_t)&rra);
	ft_opadd(trie, "rrb", (size_t)&rrb);
	ft_opadd(trie, "rrr", (size_t)&rrr);
	return (trie);
}

void		ft_opcall(t_trie *trie, const char *op,
					t_dblst *stack_a, t_dblst *stack_b)
{
	t_data	*data;

	if ((data = ft_triefind(trie, op)))
		((void (*)(t_dblst *, t_dblst *, int))*(size_t *)
			data->content)(stack_a, stack_b, 0);
	else
		ft_die(ERROR_MSG, 1);
}
