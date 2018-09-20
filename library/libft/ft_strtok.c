/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:45:01 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/20 16:07:37 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_co_wo(char *s)
{
	int		co;
	int		i;

	co = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		co++;
	}
	return (co);
}

static char		**ft_split(char **an, char *s)
{
	int		start;
	int		end;
	int		i;

	end = 0;
	i = 0;
	while (s[end])
	{
		while (s[end] == ' ' || s[end] == '\t')
			end++;
		start = end;
		while (s[end] && s[end] != ' ' && s[end] != '\t')
			end++;
		if (start < end)
		{
			an[i] = ft_strsub(s, start, end - start);
			i++;
		}
	}
	an[i] = NULL;
	return(an);
}

char			**ft_strtok(char *s)
{
	char	**an;

	if (s == NULL)
		return (NULL);
	an = (char **)malloc(sizeof(an) * (ft_co_wo(s) + 1));
	if (!an)
		return (NULL);
	ft_split(an, s);
	return (an);
}