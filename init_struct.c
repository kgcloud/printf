/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:10:32 by cloud             #+#    #+#             */
/*   Updated: 2021/02/02 18:08:22 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_printf *kg)
{
	kg->val = 0;
	kg->neg = 0;
	kg->len = 0;
	kg->pad_o = 0;
	kg->nbr_o = 0;
	kg->gauche = 0;
	kg->droite = 0;
	kg->nbr_car = 0;
	kg->nbr_esp = 0;
	kg->nbr_o_e = 0;
	kg->cham_pre = 0;
	kg->cham_neg = 0;
	kg->val_cham = 0;
	kg->p_ispec = 0;
	kg->p_sign = 0;
	kg->p_val = 0;
}
