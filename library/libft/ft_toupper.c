/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:24:11 by jpirzent          #+#    #+#             */
/*   Updated: 2018/05/22 10:39:39 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if ((ft_isalpha(c) == 1) && (c >= 97) && (c <= 122))
		c = c - 32;
	return (c);
}