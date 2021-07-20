/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:38:56 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:40:11 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_prec(const char **fmt, t_list *p, va_list ap)
{
	int	prec;
	int	ans;

	if (**fmt == '.')
	{
		*fmt += 1;
		if (**fmt == '*')
		{
			prec = va_arg(ap, int);
			*fmt += 1;
		}
		else
		{
			prec = 0;
			while (ft_isnumber(**fmt))
			{
				prec = prec * 10 + char_to_int(**fmt);
				*fmt += 1;
			}
		}
		p->has_prec = 1;
		p->prec = prec;
	}
	ans = get_type(fmt, p, ap);
	return (ans);
}

static int	get_width(const char **fmt, t_list *p, va_list ap)
{
	int	width;
	int	ans;

	if (**fmt == '*' || ft_isnumber(**fmt))
	{
		if (**fmt == '*')
		{
			width = va_arg(ap, int);
			*fmt += 1;
		}
		else
		{
			width = 0;
			while (ft_isnumber(**fmt))
			{
				width = width * 10 + char_to_int(**fmt);
				*fmt += 1;
			}
		}
		p->has_width = 1;
		p->width = width;
	}
	ans = get_prec(fmt, p, ap);
	return (ans);
}

int			get_flag(const char **fmt, t_list *p, va_list ap)
{
	size_t	ans;

	while (**fmt && (**fmt == '-' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			p->has_minus = 1;
			p->has_zero = 0;
		}
		else if (**fmt == '0' && p->has_minus == 0)
			p->has_zero = 1;
		*fmt += 1;
	}
	ans = get_width(fmt, p, ap);
	return (ans);
}
