/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:10:17 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/01 12:19:40 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		k;
	int		is;
	size_t	ls;

	i = 0;
	while (haystack[i] && len > 0)
	{
		ls = len;
		k = 0;
		is = i;
		while (haystack[i] && needle[k] && haystack[i] == needle[k] && len > 0)
		{
			i++;
			k++;
			len--;
		}
		if (needle[k] == '\0')
			return ((char *)&haystack[i - k]);
		i = is + 1;
		len = ls - 1;
	}
	return (NULL);
}
