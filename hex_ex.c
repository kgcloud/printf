/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:13:29 by canjugun          #+#    #+#             */
/*   Updated: 2021/04/14 12:23:04 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	hex_ex(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
