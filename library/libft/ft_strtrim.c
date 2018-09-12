/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:13:20 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/05 11:03:28 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	k = ft_strlen(s) - 1;
	while (s[k] == '\t' || s[k] == ' ' || s[k] == '\n')
		k--;
	if (i > k)
		return (ft_strnew(0));
	len = k - i + 1;
	return (ft_strsub(s, i, len));
}
