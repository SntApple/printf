/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:47:10 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 14:47:11 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_prec(t_list *p, const char **str, char c)
{
	int ans;
	int	prec;
	int	len;

	ans = 0;
	len = ft_strlen(*str);
	prec = p->prec;
	if (*str[0] == '-')
	{
		ans += write(1, "-", 1);
		len--;
		*str += 1;
	}
	if (c == 'p')
		ans += write(1, "0x", 2);
	while (prec-- - len > 0)
		ans += write(1, "0", 1);
	if (p->has_prec && !p->prec && **str == '0')
		len = 0;
	ans += write(1, *str, len);
	return (ans);
}

static int		print_width(t_list *p, int len, const char **str)
{
	int		ans;
	char	ch;
	int		width;

	ch = ' ';
	width = p->width;
	if (p->has_zero)
		ch = '0';
	ans = 0;
	if (p->has_prec && !p->prec && **str == '0')
		len = 0;
	if (ch == '0' && *str[0] == '-')
	{
		ans += write(1, "-", 1);
		*str += 1;
	}
	if (width > 0)
		while (width-- - len > 0)
			ans += write(1, &ch, 1);
	else
		while (width++ + len < 0)
			ans += write(1, &ch, 1);
	return (ans);
}

static void		pre_print(t_list *p, char c)
{
	if (p->width < 0)
	{
		p->has_minus = 1;
		p->has_zero = 0;
	}
	if (c == 'p' && p->has_width)
	{
		if (p->width > 2)
			p->width -= 2;
		else if (p->width < -2)
			p->width += 2;
		else
			p->width = 0;
	}
}

int				print_num(const char *str, t_list *p, char c)
{
	int	ans;
	int	len;

	pre_print(p, c);
	if (p->has_prec && p->prec >= 0)
		p->has_zero = 0;
	len = ft_strlen(str);
	if (p->prec < 0)
		p->has_prec = 0;
	else if (p->prec > len)
		len = p->prec;
	if (!(p->prec < len) && str[0] == '-')
		len++;
	ans = 0;
	if (!p->has_minus)
		ans += print_width(p, len, &str);
	ans += print_prec(p, &str, c);
	if (p->has_minus)
		ans += print_width(p, len, &str);
	return (ans);
}
