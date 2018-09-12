/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:30:18 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/07 16:02:04 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_neg(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int				ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\b')
		i++;
	sign = ft_neg(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (9223372036854775807 < res && sign == -1)
		return (0);
	if (9223372036854775807 < res)
		return (-1);
	return (res * sign);
}
