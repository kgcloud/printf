/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:59:44 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:26:15 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dpad(int n, char c, int *len)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(c);
		*len = *len + 1;
	}
}

void	ft_lpad_d_one(t_printf *kg, int *len)
{
	int	i;

	i = 0;
	if (kg->pad_o && kg->neg)
	{
		ft_putchar('-');
		kg->nbr_o = 1;
	}
	while (i++ < kg->nbr_car)
	{
		if (kg->pad_o)
			ft_putchar('0');
		else
			ft_putchar(' ');
		*len = *len + 1;
	}
}

void	ft_lpad_d_two(t_printf *kg, int *len)
{
	int	i;

	i = 0;
	if (kg->pad_o && kg->neg && (!(kg->p_val >= 0 && kg->p_val <= kg->len)))
	{
		ft_putchar('-');
		kg->nbr_o = 1;
	}
	while (i++ < kg->nbr_car)
	{
		if (kg->pad_o && (!(kg->p_val >= 0 && kg->p_val <= kg->len)))
			ft_putchar('0');
		else
			ft_putchar(' ');
		*len = *len + 1;
	}
}
