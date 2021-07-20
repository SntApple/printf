/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:40:29 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:41:55 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_char(t_list *p, va_list ap, short sw)
{
	int ans;
	int	ch;

	if (!sw)
		ch = va_arg(ap, unsigned int);
	else
		ch = '%';
	ans = print_char(ch, p);
	return (ans);
}

static int	get_str(t_list *p, va_list ap)
{
	char	*str;
	int		ans;

	str = va_arg(ap, char *);
	ans = print_str(str, p);
	return (ans);
}

static int	get_dig(char c, va_list ap, int base, t_list *p)
{
	char	*s_num;
	int		num;
	int		ans;

	s_num = NULL;
	if (c == 'd' || c == 'i')
	{
		num = va_arg(ap, int);
		s_num = ft_itoa_signed(num);
	}
	else if (c == 'x' || c == 'X')
	{
		num = va_arg(ap, unsigned int);
		s_num = ft_itoa_unsigned(num, base, c);
	}
	else if (c == 'u')
	{
		num = va_arg(ap, unsigned int);
		s_num = ft_itoa_unsigned(num, base, c);
	}
	if (!s_num)
		return (0);
	ans = print_num(s_num, p, 'd');
	free(s_num);
	return (ans);
}

static int	get_pointer(va_list ap, t_list *p)
{
	unsigned long	num;
	char			*s_num;
	int				ans;

	s_num = NULL;
	num = va_arg(ap, unsigned long);
	s_num = ft_itoa_pointer(num);
	if (!s_num)
		return (0);
	ans = print_num(s_num, p, 'p');
	free(s_num);
	return (ans);
}

int			get_type(const char **fmt, t_list *p, va_list ap)
{
	int ans;

	ans = 0;
	if (**fmt == 'c')
		ans = get_char(p, ap, 0);
	else if (**fmt == 's')
		ans = get_str(p, ap);
	else if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u')
		ans = get_dig(**fmt, ap, 10, p);
	else if (**fmt == 'x' || **fmt == 'X')
		ans = get_dig(**fmt, ap, 16, p);
	else if (**fmt == 'p')
		ans = get_pointer(ap, p);
	else if (**fmt == '%')
		ans = get_char(p, ap, 1);
	return (ans);
}
