/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:46:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 14:47:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isint(const char *str)
{
	long	nb;

	if (!ft_isdec(str))
		ft_die(ERROR_MSG, 1);
	nb = ft_strtol(str, 10);
	if (INT_MAX < nb || INT_MIN > nb)
		ft_die(ERROR_MSG, 1);
	return (nb);
}
