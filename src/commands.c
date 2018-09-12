/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:09:07 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 12:53:17 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_print_arg(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != '\"')
			ft_putchar(arg[i]);
		i++;
	}
}

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
			ft_putstr("\e[0;32m");
            ft_print_arg(split[i]);
            ft_putchar(' ');
			ft_putstr("\e[0m");
            i++;
        }
    }
    ft_putchar('\n');
}