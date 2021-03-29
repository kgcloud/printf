/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:19:55 by canjugun          #+#    #+#             */
/*   Updated: 2021/02/10 17:25:21 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pad_s(int n, int *len)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(' ');
		*len = *len + 1;
	}
}

void	ft_update_s(t_printf *kg, char *tmp)
{
	kg->len = ft_strlen(tmp);
	if (kg->val_cham >= kg->len)
		kg->nbr_car = kg->val_cham - kg->len;
	if (kg->p_val < kg->val_cham && kg->len < kg->p_val)
		kg->nbr_car = kg->val_cham - kg->len;
	if (!kg->p_sign)
		if (kg->p_val)
			kg->len = kg->p_val;
	if (kg->p_ispec && !kg->p_val)
		kg->len = 0;
	if (kg->p_ispec && kg->p_val == 0)
		kg->nbr_car = kg->val_cham;
	if (kg->p_val > 0 && kg->p_val < kg->val_cham)
		kg->nbr_car = kg->val_cham - kg->p_val;
}

void	ft_write_s(t_printf *kg, int *len, char *tmp)
{
	if (kg->gauche)
	{
		if (kg->p_val > ft_strlen(tmp))
			kg->nbr_car = kg->val_cham - ft_strlen(tmp);
		ft_print_pad_s(kg->nbr_car, len);
		ft_putstr(tmp, len, kg);
	}
	else if (kg->droite)
	{
		if (kg->p_val > ft_strlen(tmp))
			kg->nbr_car = kg->val_cham - ft_strlen(tmp);
		ft_putstr(tmp, len, kg);
		ft_print_pad_s(kg->nbr_car, len);
	}
}

int		ft_conv_s(va_list ap, char *flag, int *len)
{
	t_printf	*kg;
	char		*tmp;

	tmp = NULL;
	kg = NULL;
	if (!(kg = malloc(sizeof(t_printf))))
		return (-1);
	init_struct(kg);
	read_flag(ap, kg, flag);
	if (ft_limit(kg->val_cham) || ft_limit(kg->p_val))
	{
		free(kg);
		return (-1);
	}
	if (!(tmp = ft_strdup(va_arg(ap, const char*))))
		if (!(tmp = ft_strdup("(null)")))
			return (-1);
	ft_update_s(kg, tmp);
	ft_write_s(kg, len, tmp);
	free(kg);
	free(tmp);
	return (0);
}
