/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:17:40 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 19:44:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isflag(char ***argv, t_flags *flags)
{
	if (0 == ft_strcmp(**argv, "-v"))
	{
		++(*argv);
		flags->debug = 1;
		return (1);
	}
	return (0);
}

static void	argparse(t_dblst *lst, char *str)
{
	t_list	*it;
	t_list	*nums;
	t_data	*data;
	int		nb;

	nums = ft_splitws_lst(str);
	it = nums;
	if (!it)
		ft_die(ERROR_MSG, 1);
	while (it)
	{
		nb = ft_isint(it->content);
		if (ft_dblsthas(lst, &nb, &intcmp))
			ft_die(ERROR_MSG, 1);
		data = ft_datanew(&nb, sizeof(int));
		ft_dblstsnoc(lst, data);
		it = it->next;
	}
	ft_lstdel(&nums, &strfree);
}

static void	nargsparse(t_dblst *lst, char **argv, t_flags *flags)
{
	int	nb;

	while (*argv)
	{
		isflag(&argv, flags);
		nb = ft_isint(*argv++);
		if (ft_dblsthas(lst, &nb, &intcmp))
			ft_die(ERROR_MSG, 1);
		ft_dblstsnoc(lst, ft_datanew(&nb, sizeof(int)));
	}
}

t_dblst		*ft_inputparse(int argc, char **argv, t_flags *flags)
{
	t_dblst	*lst;

	lst = ft_dblstnew();
	if (2 == argc)
		argparse(lst, argv[1]);
	else
	{
		++argv;
		if (isflag(&argv, flags) && 3 == argc)
			argparse(lst, *argv);
		else
			nargsparse(lst, argv, flags);
	}
	return (lst);
}
