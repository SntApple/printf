/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:34:55 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:38:27 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	short		has_minus;
	short		has_zero;
	short		has_width;
	short		has_prec;
	int			width;
	int			prec;
}				t_list;

int				ft_printf(const char *fmt, ...);
int				get_flag(const char **fmt, t_list *p, va_list ap);
int				ft_isnumber(char c);
int				char_to_int(char c);
int				get_type(const char **fmt, t_list *p, va_list ap);
char			*ft_itoa_signed(int num);
char			*ft_itoa_unsigned(unsigned int num, int base, char c);
char			*ft_itoa_pointer(unsigned long num);
int				print_char(char sh, t_list *p);
int				print_str(char *str, t_list *p);
int				print_num(const char *str, t_list *p, char c);
size_t			ft_strlen(const char *str);
int				abs(int num);

#endif
