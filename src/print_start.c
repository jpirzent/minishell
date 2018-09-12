/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:53:04 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 12:12:47 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    print_start(void)
{
    ft_printf("\e[1;34m************************************************************\n");
    ft_printf("Built-ins that currently work:\n");
    ft_printf("\t\t=> echo\n");
    ft_printf("************************************************************\n\e[0m");
}