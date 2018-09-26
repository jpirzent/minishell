/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:30:21 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/25 10:23:37 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(size_t num, ...)
{
	va_list		l1;
	va_list		l2;
	char		*ret;
	size_t		i;
	size_t		len;

	len = 0;
	va_start(l1, num);
	va_copy(l2, l1);
	i = 0;
	while (i < num)
	{
		len = len + ft_strlen(va_arg(l1, char *));
		i++;
	}
	va_end(l1);
	ret = (char *)ft_strnew(len + 1);
	i = 0;
	while(i < num)
	{
		ft_strlcat(ret, va_arg(l2, char *), len + 1);
		i++;
	}
	va_end(l2);
	return (ret);
}