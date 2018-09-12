/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:06:47 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/08 08:45:26 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_decnum(int x)
{
	int		i;

	i = 0;
	if (x == 0)
		i++;
	else if (x < 0)
	{
		x = x * -1;
		while (x > 0)
		{
			i++;
			x = x / 10;
		}
		return (i + 1);
	}
	else
		while (x > 0)
		{
			i++;
			x = x / 10;
		}
	return (i);
}

static char		*ft_do_itoa(char *new, int a)
{
	int		i;
	int		s;

	i = 0;
	s = 1;
	if (a < 0)
	{
		s = -1;
		a = a * -1;
	}
	if (a == 0)
		new[i++] = '0';
	else
		while (a > 0)
		{
			new[i++] = a % 10 + '0';
			a = a / 10;
		}
	if (s == -1)
		new[i++] = '-';
	new[i] = '\0';
	ft_strrev(new);
	return (new);
}

char			*ft_itoa(int a)
{
	char	*new;

	if (a == -2147483648)
		return (ft_strdup("-2147483648"));
	new = ft_strnew(ft_decnum(a));
	if (!new)
		return (NULL);
	return (ft_do_itoa(new, a));
}
