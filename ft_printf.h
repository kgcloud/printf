/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:47:59 by cloud             #+#    #+#             */
/*   Updated: 2021/04/15 16:45:38 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_format
{
	int			val;
	int			neg;
	int			len;
	int			pad_o;
	int			nbr_o;
	int			gauche;
	int			droite;
	int			nbr_car;
	int			nbr_esp;
	int			nbr_o_e;
	int			cham_pre;
	int			cham_neg;
	int			val_cham;
	int			p_ispec;
	int			p_sign;
	int			p_val;
}				t_printf;

int				ft_printf(const char *s, ...);
int				start(va_list ap, const char *s, int *len, int *i);
int				flag_len(const char *src);
int				ft_type(char c);
int				ft_strlen(char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putchar(char c);
int				ft_conv_c(va_list ap, char *flag, int *len, char a);
int				ft_limit(int n);
void			init_struct(t_printf *kg);
int				transit(va_list ap, char *flag, int *len);
int				nbr_ex(int n);
t_printf		*read_flag(va_list ap, t_printf *kg, char *flag);
int				ft_conv_c(va_list ap, char *flag, int *len, char a);
int				ft_atoi(char *s);
char			*ft_flagdup(const char *src);
void			ft_puthex(unsigned long nbl, char c, int *len);
int				ft_conv_p(va_list ap, char *flag, int *len);
int				hex_ex(unsigned long n);
int				ft_conv_s(va_list ap, char *flag, int *len);
void			ft_print_pad_s(int n, int *len);
char			*ft_strdup(const char *s1);
void			ft_putstr(char *s, int *len, t_printf *kg);
int				ft_conv_d(va_list ap, char *flag, int *len);
void			ft_print_dpad(int n, char c, int *len);
void			ft_lpad_d_one(t_printf *kg, int *len);
void			ft_lpad_d_two(t_printf *kg, int *len);
void			ft_hex(unsigned int n, char c, int *len);
int				ft_conv_x(va_list ap, char *flag, int *len);
int				ft_atoi(char *s);
int				ft_conv_u(va_list ap, char *flag, int *len);
void			ft_puthex(unsigned long nbl, char c, int *len);
void			ft_putnbr(int nb, int *len);
void			ft_putu(unsigned int n, int *len);
int				hex_ex(unsigned long n);
int				nbr_u(unsigned int n);
void			ft_write_c(t_printf *kg, int i, char c);
void			ft_write_p(t_printf *kg, int *len, int i, unsigned long n);
void			ft_write_x(t_printf *kg, int *len, char c, unsigned int n);
void			write_x(t_printf *kg, int *len, char c, unsigned int n);
unsigned int	ft_update_x(t_printf *kg, va_list ap, unsigned int n);
int				ft_update_d(va_list ap, t_printf *kg, int n);
void			ft_write_d(int *len, t_printf *kg, int n);
void			write_d(int *len, t_printf *kg, int n);
void			ft_update_s(t_printf *kg, char *tmp);
void			ft_write_s(t_printf *kg, int *len, char *tmp);
unsigned int	ft_update_u(unsigned n, t_printf *kg, va_list ap);
void			ft_write_u(int *len, t_printf *kg, unsigned int n);
void			write_u(int *len, t_printf *kg, unsigned int n);
void			read_suite(va_list ap, t_printf *kg, char *flag, int *i);
void			read_next(va_list ap, t_printf *kg, char *flag, int *i);
int				ft_return(t_printf *kg);

#endif
