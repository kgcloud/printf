/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:47:35 by cloud             #+#    #+#             */
/*   Updated: 2021/04/14 12:37:32 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	transit(va_list ap, char *flag, int *len)
{
	char	c;
	int		n;

	n = 0;
	c = flag[ft_strlen(flag) - 1];
	if (c == 'c')
		n = ft_conv_c(ap, flag, len, '\0');
	else if (c == '%')
		n = ft_conv_c(ap, flag, len, '%');
	else if (c == 'p')
		n = ft_conv_p(ap, flag, len);
	else if (c == 's')
		n = ft_conv_s(ap, flag, len);
	else if ((c == 'd') || (c == 'i'))
		n = ft_conv_d(ap, flag, len);
	else if (c == 'u')
		n = ft_conv_u(ap, flag, len);
	else if ((c == 'x') || (c == 'X'))
		n = ft_conv_x(ap, flag, len);
	if (n == -1)
		return (-1);
	return (0);
}
