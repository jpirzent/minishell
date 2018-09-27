/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:07:19 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/27 14:39:18 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_line(char *line)
{
	char	**split;

	if (!(split = ft_strtok(line)))
		return ;
	if (split[0] == 0 || split[0] == NULL)
		return ;
	else if (ft_strequ(split[0], "exit"))
		ft_exit(line, split);
	else if (ft_strequ(split[0], "echo"))
		ft_echo(split);
	else if (ft_strequ(split[0], "env") || ft_strequ(split[0], "pwd"))
		ft_env(split);
	else if (ft_strequ(split[0], "setenv"))
		ft_setenv(split);
	else if (ft_strequ(split[0], "unsetenv"))
		ft_unsetenv(split);
	else if (ft_strequ(split[0], "cd"))
		ft_cd(split);
	else if (ft_strequ(split[0], "help"))
		ft_help();
	else
		ft_env_cmd(split[0], split);
	ft_freetab(split);
	split = NULL;
}
