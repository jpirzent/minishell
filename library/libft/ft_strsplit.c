/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:06:53 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/06 16:07:52 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_co_wo(const char *s, char c)
{
	int		co;
	int		i;

	co = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		co++;
	}
	return (co);
}

static char		**ft_split(char **an, const char *s, char c)
{
	int		start;
	int		end;
	int		i;

	end = 0;
	i = 0;
	while (s[end])
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (start < end)
		{
			an[i] = ft_strsub(s, start, end - start);
			i++;
		}
	}
	an[i] = NULL;
	return (an);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**an;

	if (s == NULL)
		return (NULL);
	an = (char **)malloc(sizeof(an) * (ft_co_wo(s, c) + 1));
	if (!an)
		return (NULL);
	ft_split(an, s, c);
	return (an);
}
