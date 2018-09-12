/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:07:19 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 17:00:16 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    print_line(char **line, char **envp)
{
    int     i;
    char    **split;
    
    i = 0;
    split = ft_strsplit(line[0], ' ');
    if (ft_strequ(split[0], "exit"))
        exit(0);
    else if (ft_strequ(split[0], "echo"))
        ft_echo(split);
	else if (ft_strequ(split[0], "env"))
		ft_env(envp);
	else if (ft_strequ(split[0], "setenv"))
		ft_setenv(split, envp);
    else
        ft_printf("\e[1;31minvalid arg\n\e[0m");
}