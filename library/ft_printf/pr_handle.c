/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:46:59 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/06 15:25:40 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_handle(char fmt, va_list list)
{
	if (fmt == 's' || fmt == 'c')
		return (pr_chars(fmt, list));
	else if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		return (pr_ints(fmt, list));
	else if (fmt == 'o' || fmt == 'x' || fmt == 'X')
		return (pr_base(fmt, list));
	else if (fmt == 'S' || fmt == 'C')
		return (pr_wchars(fmt, list));
	else if (fmt == 'D' || fmt == 'O' || fmt == 'U')
		return (pr_cints(fmt, list));
	else if (fmt == 'p')
		return (pr_padd(list));
	else
		return (-1);
}
