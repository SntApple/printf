/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:46:57 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 14:46:59 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus(t_list *p)
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
			while (width++ < -1)
			{
				write(1, &ch, 1);
				ans++;
			}
		else
			while (width-- > 1)
			{
				write(1, &ch, 1);
				ans++;
			}
	}
	return (ans);
}

int			print_char(char c, t_list *p)
{
	int ans;

	ans = 0;
	if (p->has_width && p->width < 0)
	{
		p->has_minus = 1;
		p->has_zero = 0;
	}
	if (p->has_minus)
	{
		write(1, &c, 1);
		ans++;
	}
	ans += print_minus(p);
	if (p->has_zero || !p->has_minus)
	{
		write(1, &c, 1);
		ans++;
	}
	return (ans);
}
