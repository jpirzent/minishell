/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:53:04 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/27 15:14:31 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_start(void)
{
	ft_printf("\e[1;34m****************************************************\n");
	ft_printf("Built-ins that currently work:\n");
	ft_printf("\t=> echo\n\t=> env\n\t=> setenv\n\t=> unsetenv\n\t=> pwd\n\t");
	ft_printf("=> cd\n\t=> any system calls\n");
	ft_printf("****************************************************\n\e[0m");
	ft_putstr("\e[0;35m>>===|>\t\e[0;33m");
}
