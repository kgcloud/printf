/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:36:45 by canjugun          #+#    #+#             */
/*   Updated: 2021/02/02 18:13:00 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flagdup(const char *src)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char) * (flag_len(src) + 1));
	if (!dst)
		return (NULL);
	while (src[i] && i <= flag_len(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
