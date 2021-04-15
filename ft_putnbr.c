/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:56:45 by cloud             #+#    #+#             */
/*   Updated: 2021/04/14 12:20:28 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	char			*base;
	unsigned int	n;

	base = "0123456789";
	n = 0;
	if (nb < 0)
	{
		n = (unsigned)nb * -1;
		nb *= -1;
		*len = *len + 1;
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putchar(base[n % 10]);
		*len = *len + 1;
	}
	else
	{
		ft_putchar(base[n % 10]);
		*len = *len + 1;
	}
}
