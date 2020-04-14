/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:07:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 16:43:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_queue	*opread(void)
{
	int		n;
	t_queue	*queue;
	char	*line;

	queue = ft_queuenew(NULL, 0);
	while ((n = get_next_line(0, &line)))
		ft_enqueue(queue, line, ft_strlen(line) + 1);
	return (queue);
}

void			ft_check(t_dblst *stack_a, t_flags *flags)
{
	t_dblst	*stack_b;
	t_trie	*trie;
	t_queue	*queue;
	t_list	*op;

	stack_b = ft_dblstnew();
	trie = ft_opsetup();
	queue = opread();
	while (!ft_queue_isempty(queue))
	{
		op = ft_dequeue(queue);
		ft_opcall(trie, op->content, stack_a, stack_b);
		if (flags->debug)
			stacksput(stack_a, stack_b);
		ft_lstdel(&op, &strfree);
	}
	if (ft_issorted(stack_a, stack_b))
		ft_printf("\033[1;32mOK\033[0m\n");
	else
		ft_printf("\033[1;31mKO\033[0m\n");
	ft_queuedel(&queue, &strfree);
	ft_dblstdel(&stack_a, &intfree);
	ft_dblstdel(&stack_b, &intfree);
	ft_triedel(&trie, &intfree);
}
