/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_wchars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:45:43 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/13 16:54:05 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pr_wchars(char fmt, va_list list)
{
	wchar_t		wc;
	wchar_t		*ws;

	if (fmt == 'C')
	{
		wc = va_arg(list, wchar_t);
		return (pr_putwchar(wc));
	}
	else if (fmt == 'S')
	{
		ws = va_arg(list, wchar_t *);
		return (pr_putwstr(ws));
	}
	else
		return (-1);
}

static char	pr_wcsize(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc >= 128 && wc <= 2047)
		return (2);
	else if (wc >= 2048 && wc <= 65535)
		return (3);
	else if (wc >= 65536 && wc <= 2097151)
		return (4);
	else
		return (0);
}

int			pr_putwchar(wchar_t wc)
{
	int				c;
	char			size;
	unsigned char	byte;

	c = 0;
	size = pr_wcsize(wc);
	if (size == 1)
		return (pr_putchar(wc));
	byte = (260 << (4 - size)) | (wc >> ((size - 1) * 6));
	c += pr_putchar(byte);
	size--;
	while (size--)
	{
		byte = ((wc >> ((size) * 6)) & 63) | 128;
		c += pr_putchar(byte);
	}
	return (c);
}

int			pr_putwstr(wchar_t *ws)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	if (ws == NULL)
		return (pr_putstr("(null)"));
	while (ws[i] != '\0')
		c += pr_putwchar(ws[i++]);
	return (c);
}

int			pr_cints(char fmt, va_list list)
{
	intmax_t		n;

	if (fmt == 'D')
	{
		n = va_arg(list, long);
		return (pr_putnbr(n));
	}
	else if (fmt == 'U')
	{
		n = va_arg(list, long);
		return (pr_putulong(n));
	}
	else if (fmt == 'O')
	{
		n = va_arg(list, long);
		if (n < 0)
			n = UINT_MX + n;
		return (pr_putnbr_b(n, 8));
	}
	else
		return (-1);
}
