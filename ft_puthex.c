/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:10:54 by canjugun          #+#    #+#             */
/*   Updated: 2021/02/02 18:04:15 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nbl, char c, int *len)
{
	int			i;
	long long	nb[15];
	char		*base;

	i = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbl == 0)
	{
		ft_putchar('0');
		*len = *len + 1;
		return ;
	}
	while (nbl)
	{
		nb[i++] = nbl % 16;
		nbl = nbl / 16;
		*len = *len + 1;
	}
	while (i-- > 0)
		ft_putchar(base[nb[i]]);
}
