/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:47:03 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 14:47:04 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus(t_list *p, int len)
{
	int		width;
	char	ch;
	int		ans;

	ch = ' ';
	ans = 0;
	if (p->has_zero)
		ch = '0';
	if (p->has_width)
	{
		width = p->width;
		if (width < 0)
			while ((width++ + len) < 0)
			{
				write(1, &ch, 1);
				ans++;
			}
		else
			while ((width-- - len) > 0)
			{
				write(1, &ch, 1);
				ans++;
			}
	}
	return (ans);
}

int			print_str(char *str, t_list *p)
{
	int	len;
	int ans;

	ans = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (p->has_prec && p->prec < len && p->prec >= 0)
		len = p->prec;
	if (p->has_width && p->width < 0)
	{
		p->has_minus = 1;
		p->has_zero = 0;
	}
	if (p->has_minus)
		ans += write(1, str, len);
	ans += print_minus(p, len);
	if (p->has_zero || !p->has_minus)
		ans += write(1, str, len);
	return (ans);
}
