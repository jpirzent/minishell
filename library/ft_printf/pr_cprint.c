/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_cprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:57:52 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 15:25:50 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_ints(char fmt, va_list list)
{
	int		i;
	long	l;

	if (fmt == 'd' || fmt == 'i')
	{
		i = va_arg(list, int);
		return (pr_putnbr(i));
	}
	else if (fmt == 'u')
	{
		l = va_arg(list, int);
		return (pr_putuint(l));
	}
	else
		return (-1);
}

int		pr_chars(char fmt, va_list list)
{
	char	*s;
	char	c;

	if (fmt == 'c')
	{
		c = va_arg(list, int);
		return (pr_putchar(c));
	}
	else if (fmt == 's')
	{
		s = va_arg(list, char *);
		return (pr_putstr(s));
	}
	else
		return (-1);
}

int		pr_base(char fmt, va_list list)
{
	long	i;

	if (fmt == 'o')
	{
		i = va_arg(list, int);
		if (i < 0)
			i = UINT_MX + i;
		return (pr_putnbr_b(i, 8));
	}
	else if (fmt == 'x')
	{
		i = va_arg(list, int);
		if (i < 0)
			i = UINT_MX + i;
		return (pr_putnbr_b(i, 16));
	}
	else if (fmt == 'X')
	{
		i = va_arg(list, int);
		if (i < 0)
			i = UINT_MX + i;
		return (pr_putcx(i));
	}
	else
		return (-1);
}

int		pr_padd(va_list list)
{
	void	*p;

	p = va_arg(list, void *);
	return (pr_printaddress(p));
}
