/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:40:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/01 12:06:32 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;
	int		is;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		k = 0;
		is = i;
		while (haystack[i] == needle[k] && needle[k] && haystack[i])
		{
			i++;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)&haystack[i - k]);
		i = is + 1;
	}
	return (NULL);
}
