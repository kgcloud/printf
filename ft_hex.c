/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:45:05 by cloud             #+#    #+#             */
/*   Updated: 2021/04/14 12:22:43 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int n, char c, int *len)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hex(n / 16, c, len);
		ft_putchar(base[n % 16]);
		*len = *len + 1;
	}
	else
	{
		ft_putchar(base[n % 16]);
		*len = *len + 1;
	}
}
