/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:09:07 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 17:20:06 by jpirzent         ###   ########.fr       */
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
			ft_putstr("\e[0;32m");
            ft_print_arg(split[i]);
            ft_putchar(' ');
			ft_putstr("\e[0m");
            i++;
        }
    }
    ft_putchar('\n');
}

void	ft_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_printf("\e[0;32m%s\n", envp[i]);
		i++;
	}
}

void	ft_setenv(char **split, char **envp)
{
	int		i;

	i = 0;
	if (check_envp(envp, split[1]) == 1)
	{
		i = find_var(split[1], envp);
		change_line(split[1], envp);
	}
	else
		add_var(split[1], envp);
}