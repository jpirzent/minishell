/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:02:32 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/20 14:58:38 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char		*cmd_loc(char *cmd)
{
	char	*exec;
	char	**path_split;
	int		i;

	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	if ((i = find_var("PATH=")) < 0)
	{
		ft_printf("\e[1;31mPATH is unset\e[0m\n");
		return (NULL);
	}
	else
	{
		path_split = ft_strsplit(get_pwd(env_cp[i]), ':');
		if (!path_split)
			return (NULL);
		i = 0;
		while (path_split[i])
		{
			exec = ft_strjoin(path_split[i], "/");
			exec = ft_strjoin(exec, cmd);
			if (!access(exec, F_OK))
				break ;
			free(exec);
			i++;
		}
		return(exec);
	}
}

void	ft_env_cmd(char *cmd, char **split)
{
	pid_t	pid;
	pid_t	wpid;
	char	*exec;
	int		stts;

	exec = cmd_loc(cmd);
	pid = fork();
	if (pid == 0)
	{
		if (execve(exec, split, env_cp) == -1)
			ft_printf("\e[1;31mcommand: %s not found!\n", cmd);
		exit (EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_printf("\e[1;31mFork Failure!\n");
	else
		wpid = waitpid(pid, &stts, WUNTRACED);
}