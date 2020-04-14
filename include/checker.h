/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:31:10 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 13:30:03 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"

void		ft_check(t_dblst *stack_a, t_flags *flags);
t_trie		*ft_opsetup(void);
void		ft_opcall(t_trie *trie, const char *op,
				t_dblst *stack_a, t_dblst *stack_b);

#endif
