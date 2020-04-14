/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:31:57 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 13:28:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_flags	flags;

	if (1 == argc)
	{
		ft_printf("%s\n", USAGE_MSG);
		return (EXIT_FAILURE);
	}
	ft_bzero(&flags, sizeof(t_flags));
	ft_check(ft_inputparse(argc, argv, &flags), &flags);
	return (EXIT_SUCCESS);
}
