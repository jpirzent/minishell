/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:36:12 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/10 15:28:01 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		list;
	int			i;
	int			c;

	va_start(list, format);
	i = -1;
	c = 0;
	while (format[++i])
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				c += pr_putchar('%');
			else
				while (ft_isalpha(format[i + 1]) == 0 && format[i])
					i++;
			if (format[i] == '\0')
				break ;
			c += pr_start(format[i + 1], list);
			i++;
		}
		else if (format[i] != '%')
			c += pr_putchar(format[i]);
	va_end(list);
	return (c);
}

int		pr_chval(char fmt)
{
	const char	*s = "spdSDioOuUxXcC";
	int			i;
	int			q;

	i = 0;
	q = 0;
	while (s[i])
	{
		if (s[i] == fmt)
			q = 1;
		i++;
	}
	if (q == 0 && fmt == '%')
		q = 1;
	return (q);
}

int		pr_start(char fmt, va_list list)
{
	int		temp;

	if (pr_chval(fmt) == 1)
	{
		temp = pr_handle(fmt, list);
		if (temp >= 0)
			return (temp);
		else
			return (0);
	}
	else
		return (0);
}
