/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:28:30 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 13:30:11 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;

	if (1 == argc)
	{
		ft_printf("%s\n", USAGE_MSG);
		return (EXIT_FAILURE);
	}
	ft_bzero(&flags, sizeof(t_flags));
	ft_sort(ft_inputparse(argc, argv, &flags));
	return (EXIT_SUCCESS);
}
