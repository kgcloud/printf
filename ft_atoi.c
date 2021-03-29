/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:41:20 by cloud             #+#    #+#             */
/*   Updated: 2021/02/02 18:12:33 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *s)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + *s++ - '0';
	return (res * neg);
}
