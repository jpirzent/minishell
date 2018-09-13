/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:20 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/13 14:55:13 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_envp(char **envp, char *var)
{
	int		i;
	char	*env_name;
	char	*var_name;

	i = 0;
	while (envp[i] != NULL)
	{
		env_name = ft_find_char(envp[i], '=');
		var_name = ft_find_char(var, '=');
		if (ft_strequ(env_name, var_name))
		{
			free(env_name);
			free(var_name);
			return (1);
		}
		else
			i++;
	}
	free(env_name);
	free(var_name);
	return (0);
}

void	ft_add_var(char *var, char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	envp[i] = ft_strdup(var);
	envp[i + 1] = NULL;
}

int		find_var(char *var, char **envp)
{
	int		i;
	char	*ename;
	char	*vname;

	i = 0;
	vname = ft_find_char(var, '=');
	while (envp[i] != NULL)
	{
		ename = ft_find_char(envp[i], '=');
		if (ft_strequ(vname, ename))
		{
			free(vname);
			free(ename);
			return (i);
		}
		i++;
	}
	free(vname);
	free(ename);
	return (-1);
}

void	change_line(char *var, char **envp, int i)
{
	ft_bzero((void *)envp[i], ft_strlen(envp[i]));
	ft_strcpy(envp[i], var);
}
