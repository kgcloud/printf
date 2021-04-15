/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:47:42 by cloud             #+#    #+#             */
/*   Updated: 2021/04/14 12:37:03 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}

int	flag_len(const char *src)
{
	int	i;

	i = 0;
	while (src[i] && !ft_type(src[i]))
		i++;
	return (i);
}

int	start(va_list ap, const char *s, int *len, int *i)
{
	int		j;
	char	*tmp;

	j = *i;
	if (s[j + 1] == '%')
	{
		ft_putchar('%');
		j++;
	}
	else
	{
		tmp = ft_flagdup(&s[j + 1]);
		if (tmp == NULL)
			return (-1);
		if (transit(ap, tmp, len) == -1)
		{
			free(tmp);
			return (-1);
		}
		j += ft_strlen(tmp);
		*len = *len - 1;
		free(tmp);
	}
	*i = j;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	va_start(ap, s);
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (start(ap, s, &len, &i) == -1)
				return (-1);
		}
		else
			ft_putchar(s[i]);
		i++;
		len++;
	}
	va_end(ap);
	return (len);
}
