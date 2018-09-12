/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:41:03 by jpirzent          #+#    #+#             */
/*   Updated: 2018/07/11 17:41:26 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbnbr(int base, long num)
{
	long	i;
	char	*arr;

	arr = "0123456789abcdef";
	i = num;
	if (i >= base)
	{
		ft_putbnbr(base, i / base);
		ft_putbnbr(base, i % base);
	}
	else if (base == 16)
		ft_putchar(arr[i]);
	else
		ft_putchar(i + '0');
}
