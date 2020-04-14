/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsizet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:33:17 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/08 16:33:34 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsizet(size_t nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putsizet(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}