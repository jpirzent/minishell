/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:35:59 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/04 15:23:48 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	int					k;
	char				*new;

	k = 0;
	if (s == NULL || len == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!(new))
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	while (len > 0)
	{
		new[k] = s[i];
		i++;
		k++;
		len--;
	}
	new[k] = '\0';
	return (new);
}
