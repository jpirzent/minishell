/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:23:35 by jpirzent          #+#    #+#             */
/*   Updated: 2018/07/11 17:35:05 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchex(long n)
{
	char	*arr;

	if (n < 0)
		n = 4294967296 + n;
	arr = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putchex(n / 16);
		ft_putchex(n % 16);
	}
	else
		ft_putchar(arr[n]);
}
