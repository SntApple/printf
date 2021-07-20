/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:34:48 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:36:12 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	init_list(void)
{
	t_list	p;

	p.has_minus = 0;
	p.has_prec = 0;
	p.has_width = 0;
	p.has_zero = 0;
	p.prec = 0;
	p.width = 0;
	return (p);
}

static int		get_parse(const char *fmt, va_list ap)
{
	t_list	p;
	size_t	ans;

	ans = 0;
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			write(1, fmt, 1);
			fmt++;
			ans++;
		}
		if (*fmt)
		{
			p = init_list();
			fmt++;
			ans += get_flag(&fmt, &p, ap);
		}
		if (*fmt)
			fmt++;
	}
	return (ans);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	ans;

	ans = 0;
	va_start(ap, fmt);
	ans += get_parse(fmt, ap);
	va_end(ap);
	return (ans);
}
