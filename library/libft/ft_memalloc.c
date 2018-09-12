/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:45:03 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/08 12:53:08 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size);
	if (!(new))
		return (NULL);
	ft_memset((void *)new, '\0', size);
	return (new);
}
