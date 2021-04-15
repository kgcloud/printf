/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:07:10 by canjugun          #+#    #+#             */
/*   Updated: 2021/04/14 12:20:54 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len, t_printf *kg)
{
	int	i;

	i = 0;
	if (s[0] == '\0' && ((!kg->p_ispec) || (kg->p_ispec && kg->p_val)))
	{
		if (kg->cham_pre)
		{
			ft_putchar(' ');
			*len = *len + 1;
		}
		return ;
	}
	while (s[i] && i < kg->len)
	{
		write(1, &s[i], 1);
		*len = *len + 1;
		i++;
	}
}
