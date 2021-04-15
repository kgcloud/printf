/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:14:48 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:23:44 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_update_u(unsigned n, t_printf *kg, va_list ap)
{
	n = va_arg(ap, unsigned);
	kg->val = n;
	kg->len = nbr_u(n);
	if (kg->gauche || kg->droite || kg->pad_o)
		kg->nbr_car = kg->val_cham - nbr_u(n);
	if (kg->p_val > kg->len)
	{
		kg->nbr_o_e = kg->p_val - kg->len + kg->neg;
		kg->nbr_esp = kg->val_cham - kg->p_val;
	}
	if (kg->neg && kg->p_val == kg->len)
	{
		kg->nbr_o_e += 1;
		kg->nbr_esp = kg->val_cham - kg->p_val;
		kg->nbr_car -= 1;
	}
	return (n);
}

void	ft_write_u(int *len, t_printf *kg, unsigned int n)
{
	if (!kg->p_ispec)
		ft_lpad_d_one(kg, len);
	else if (kg->nbr_esp == 0 && kg->nbr_o_e == 0)
		ft_lpad_d_two(kg, len);
	if (kg->nbr_esp)
		ft_print_dpad(kg->nbr_esp, ' ', len);
	if (kg->nbr_o_e)
		ft_print_dpad(kg->nbr_o_e, '0', len);
	if (n == 0 && kg->p_ispec && kg->p_val == 0)
	{
		if (!kg->val_cham)
			return ;
		write(1, " ", 1);
		*len = *len + 1;
	}
	else
		ft_putu(n, len);
}

void	write_u(int *len, t_printf *kg, unsigned int n)
{
	if (kg->nbr_o_e)
		ft_print_dpad(kg->nbr_o_e, '0', len);
	if (n == 0 && kg->p_ispec && kg->p_val == 0)
	{
		if (!kg->val_cham)
			return ;
		write(1, " ", 1);
		*len = *len + 1;
	}
	else
		ft_putu(n, len);
	if (kg->nbr_esp)
		ft_print_dpad(kg->nbr_esp, ' ', len);
	if (kg->nbr_o_e == 0 && kg->nbr_esp == 0)
		ft_print_dpad(kg->nbr_car, ' ', len);
}

int	ft_conv_u(va_list ap, char *flag, int *len)
{
	t_printf		*kg;
	unsigned int	n;

	kg = NULL;
	n = 0;
	kg = malloc(sizeof(t_printf));
	if (kg == NULL)
		return (-1);
	init_struct(kg);
	kg = read_flag(ap, kg, flag);
	if (ft_limit(kg->val_cham) || ft_limit(kg->p_val))
	{
		free(kg);
		return (-1);
	}
	n = ft_update_u(n, kg, ap);
	if (kg->gauche)
		ft_write_u(len, kg, n);
	else if (kg->droite)
		write_u(len, kg, n);
	free(kg);
	return (0);
}
