/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:09:07 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 11:23:17 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_echo(char **split)
{
    int     i;

    i = 1;
    while (split[i] != NULL)
    {
        if (split[i] == NULL || split[i][0] == 0)
            i++;
        else
        {
            ft_putstr(split[i]);
            ft_putchar(' ');
            i++;
        }
    }
    ft_putchar('\n');
}