/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:42:46 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:43:46 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_pointer(unsigned long num)
{
	unsigned long	num_copy;
	int				length;
	char			*str;
	char			ch;

	length = 1;
	num_copy = num;
	while (num_copy /= 16)
		length++;
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == 0)
		return (0);
	str[length--] = '\0';
	if (!num)
		str[length] = '0';
	while (num)
	{
		ch = num % 16 + '0';
		if (ch > '9')
			ch += 39;
		str[length--] = ch;
		num /= 16;
	}
	return (str);
}

static void	ft_fill_str(int num, char *str, int length)
{
	int ch;

	while (num)
	{
		ch = num % 10;
		ch = ch > 0 ? ch : -ch;
		str[length--] = ch + '0';
		num /= 10;
	}
}

char		*ft_itoa_signed(int num)
{
	int		cnum;
	int		length;
	char	*str;

	length = 1;
	cnum = num;
	while (cnum /= 10)
		length++;
	if (num < 0)
		length++;
	if ((str = (char*)malloc(sizeof(char) * (length + 1))) == 0)
		return (NULL);
	str[length--] = '\0';
	if (!num)
		str[0] = '0';
	if (num < 0)
		str[0] = '-';
	ft_fill_str(num, str, length);
	return (str);
}

char		*ft_itoa_unsigned(unsigned int num, int base, char c)
{
	unsigned int	cnum;
	int				length;
	char			*str;
	int				ch;

	length = 1;
	cnum = num;
	while (cnum /= base)
		length++;
	if ((str = (char*)malloc(sizeof(char) * (length + 1))) == 0)
		return (NULL);
	str[length--] = '\0';
	if (!num)
		str[0] = '0';
	while (num)
	{
		ch = num % base + '0';
		if (ch > '9')
			ch += 7;
		if (ch > '9' && c == 'x')
			ch += 32;
		str[length--] = ch;
		num /= base;
	}
	return (str);
}
