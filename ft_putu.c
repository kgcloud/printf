/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:28:37 by cloud             #+#    #+#             */
/*   Updated: 2021/04/14 12:21:23 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu(unsigned int n, int *len)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
	{
		ft_putu(n / 10, len);
		ft_putchar(base[n % 10]);
		*len = *len + 1;
	}
	else
	{
		ft_putchar(base[n % 10]);
		*len = *len + 1;
	}
}
