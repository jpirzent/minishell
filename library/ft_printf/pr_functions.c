/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:56:18 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/13 16:53:00 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (pr_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		pr_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		pr_putnbr(intmax_t n)
{
	char	*s;
	int		c;

	if (n < -9223372036854775807)
		c = pr_putstr("-9223372036854775808");
	else
	{
		s = pr_itoa(n);
		c = pr_putstr(s);
		free(s);
	}
	return (c);
}

int		pr_putuint(intmax_t n)
{
	int		c;

	if (n >= 0)
		c = pr_putnbr_b(n, 10);
	else
	{
		n = UINT_MX + n;
		c = pr_putnbr_b(n, 10);
	}
	return (c);
}

int		pr_putcx(long n)
{
	int		c;
	char	*s;

	s = pr_itoa_b(n, 16);
	c = 0;
	while (s[c])
	{
		if (s[c] >= 'a' && s[c] <= 'z')
			pr_putchar(s[c] - 32);
		else
			pr_putchar(s[c]);
		c++;
	}
	free(s);
	return (c);
}
