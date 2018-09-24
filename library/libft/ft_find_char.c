/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:27:35 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/24 09:53:59 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_char(char *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			tmp = ft_strsub(s, 0, i);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}