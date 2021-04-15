/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:15:39 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:41:15 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_suite(va_list ap, t_printf *kg, char *flag, int *i)
{
	int	j;

	j = *i;
	if (flag[j] == '0')
	{
		if (kg->droite == 0)
			kg->pad_o = 1;
		while (flag[j++] && (flag[j] == '0' || flag[j] == '-'))
		{
			if (flag[j] == '-')
			{
				kg->droite = 1;
				kg->gauche = 0;
				kg->pad_o = 0;
			}
		}
	}
	if (flag[j] >= '0' && flag[j] <= '9')
	{
		kg->val_cham = ft_atoi(&flag[j]);
		j += nbr_ex(ft_atoi(&flag[j]));
		kg->cham_pre = 1;
	}
	*i = j;
	read_next(ap, kg, flag, i);
}

void	read_next(va_list ap, t_printf *kg, char *flag, int *i)
{
	int	j;

	j = *i;
	while (flag[j] && (flag[j] != '*' && flag[j] != '.'
			&& (!(flag[j] >= '0' && flag[j] <= '9'))))
		j++;
	if (flag[j] == '*' && !kg->val_cham && !kg->cham_pre)
	{
		kg->val_cham = va_arg(ap, int);
		kg->cham_pre = 1;
		if (kg->val_cham < 0)
		{
			kg->val_cham *= -1;
			kg->cham_neg = 1;
			kg->droite = 1;
			kg->gauche = 0;
		}
		j++;
	}
	if (flag[j++] == '.')
		kg->p_ispec = 1;
	*i = j;
}

t_printf	*read_flag(va_list ap, t_printf *kg, char *flag)
{
	int	i;

	i = 0;
	if (flag[i] == '-')
	{
		kg->droite = 1;
		kg->cham_neg = 1;
		while (flag[i] && flag[i] == '-')
			i++;
	}
	else
		kg->gauche = 1;
	read_suite(ap, kg, flag, &i);
	if (flag[i] >= '0' && flag[i] <= '9')
	{
		kg->p_val = ft_atoi(&flag[i]);
		i += nbr_ex(ft_atoi(&flag[i]));
	}
	else if (flag[i++] == '*' && !kg->p_val)
	{
		kg->p_val = va_arg(ap, int);
		if (kg->p_val < 0)
			kg->p_sign = 1;
	}
	return (kg);
}
