/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:02 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:11:14 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_c(t_printf *kg, int i, char c)
{
	if (kg->gauche)
	{
		while (i < kg->nbr_car)
		{
			if (c == '%' && kg->pad_o)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		while (i < kg->nbr_car)
		{
			if (c == '%' && kg->pad_o)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
}

int	ft_conv_c(va_list ap, char *flag, int *len, char a)
{
	t_printf	*kg;
	char		c;
	int			i;

	i = 0;
	kg = malloc(sizeof(t_printf));
	if (kg == NULL )
		return (-1);
	init_struct(kg);
	kg = read_flag(ap, kg, flag);
	if (ft_limit(kg->val_cham))
	{
		free(kg);
		return (-1);
	}
	c = a;
	if (a != '%')
		c = va_arg(ap, int);
	kg->nbr_car = kg->val_cham - 1;
	*len = (*len + kg->nbr_car) + 2;
	if (kg->val_cham != 0 )
		*len = *len - 1;
	ft_write_c(kg, i, c);
	free(kg);
	return (0);
}
