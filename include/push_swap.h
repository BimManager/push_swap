/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:29:22 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 15:31:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ERROR_MSG	"Error"
# define USAGE_MSG	"Usage: ./push_swap[./checker] 2 1 3 6 5 8"

typedef struct	s_flags
{
	t_uint32	debug : 1;
	t_uint32	color : 1;
}				t_flags;

void			ft_sort(t_dblst *stack_a);
void			ft_presort(t_dblst *stack_a);
t_dblst			*ft_inputparse(int argc, char **argv, t_flags *flags);

void			sa(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			sb(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			ss(t_dblst *stack_a, t_dblst *stack_b, int echo);

void			pa(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			pb(t_dblst *stack_a, t_dblst *stack_b, int echo);

void			ra(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			rb(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			rr(t_dblst *stack_a, t_dblst *stack_b, int echo);

void			rra(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			rrb(t_dblst *stack_a, t_dblst *stack_b, int echo);
void			rrr(t_dblst *stack_a, t_dblst *stack_b, int echo);

void			ft_selsort(t_dblst *stack_a, t_dblst *stack_b);
void			ft_qlikesort(t_dblst *stack_a, t_dblst *stack_b);

int				ft_isint(const char *str);
int				ft_issorted(t_dblst *stack_a, t_dblst *stack_b);

void			stacksput(t_dblst *stack_a, t_dblst *stack_b);
void			intfree(void *pint, size_t size);
int				intcmp(const void *pa, const void *pb);
void			strfree(void *str, size_t size);
int				nodecmp(t_dbnode *n1, t_dbnode *n2,
				int (*cmp)(const void *, const void *));

#endif
