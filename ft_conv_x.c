/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:32:53 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:25:41 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_update_x(t_printf *kg, va_list ap, unsigned int n)
{
	n = va_arg(ap, unsigned);
	kg->val = n;
	kg->len = hex_ex(n);
	if (kg->gauche || kg->droite || kg->pad_o)
		kg->nbr_car = kg->val_cham - hex_ex(n);
	if (kg->p_val > kg->len)
	{
		kg->nbr_o_e = kg->p_val - kg->len;
		kg->nbr_esp = kg->val_cham - kg->p_val;
	}
	return (n);
}

void	ft_write_x(t_printf *kg, int *len, char c, unsigned int n)
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
	{
		if (c == 'x')
			ft_hex(n, 'x', len);
		else
			ft_hex(n, 'X', len);
	}
}

void	write_x(t_printf *kg, int *len, char c, unsigned int n)
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
	{
		if (c == 'x')
			ft_hex(n, 'x', len);
		else
			ft_hex(n, 'X', len);
	}
	if (kg->nbr_esp)
		ft_print_dpad(kg->nbr_esp, ' ', len);
	if (kg->nbr_o_e == 0 && kg->nbr_esp == 0)
		ft_print_dpad(kg->nbr_car, ' ', len);
}

int	ft_conv_x(va_list ap, char *flag, int *len)
{
	t_printf		*kg;
	char			c;
	unsigned int	n;

	kg = NULL;
	c = flag[ft_strlen(flag) - 1];
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
	n = ft_update_x(kg, ap, n);
	if (kg->gauche)
		ft_write_x(kg, len, c, n);
	else
		write_x(kg, len, c, n);
	free(kg);
	return (0);
}
