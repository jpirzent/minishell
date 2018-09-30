/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:28:30 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/30 17:28:56 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoin(const char *s0, const char *s1, size_t len)
{
	char		*s;
	char		*r;

	s = ft_strnew(ft_strlen(s0) + len + 1);
	r = s;
	while (*s0)
		*s++ = *s0++;
	while (*s1 && len--)
		*s++ = *s1++;
	return (r);
}