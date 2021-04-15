/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:05:59 by canjugun          #+#    #+#             */
/*   Updated: 2021/04/15 16:12:31 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_p(t_printf *kg, int *len, int i, unsigned long n)
{
	if (kg->gauche)
	{
		while (i++ < kg->nbr_car)
		{
			ft_putchar(' ');
			*len = *len + 1;
		}
		write(1, "0x", 2);
		ft_puthex(n, 'x', len);
	}
	else
	{
		write(1, "0x", 2);
		ft_puthex(n, 'x', len);
		while (i++ < kg->nbr_car)
		{
			ft_putchar(' ');
			*len = *len + 1;
		}
	}
}

int	ft_conv_p(va_list ap, char *flag, int *len)
{
	t_printf		*kg;
	unsigned long	n;
	int				i;

	kg = NULL;
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
	n = va_arg(ap, unsigned long);
	kg->len = hex_ex(n);
	kg->nbr_car = kg->val_cham - kg->len - 2;
	*len = *len + 2;
	ft_write_p(kg, len, i, n);
	free(kg);
	return (0);
}
