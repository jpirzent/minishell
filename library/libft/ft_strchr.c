/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:57:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/05/30 13:34:59 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	v;

	v = (char)c;
	i = 0;
	while (s[i] && s[i] != v)
		i++;
	if (s[i] == v)
		return ((char *)&s[i]);
	else
		return (NULL);
}
