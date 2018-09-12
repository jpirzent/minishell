/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:25:50 by jpirzent          #+#    #+#             */
/*   Updated: 2018/05/30 13:34:42 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	v;

	i = 0;
	v = (char)c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == v)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
