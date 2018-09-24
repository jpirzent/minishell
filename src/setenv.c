/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:20 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/24 17:35:34 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_envp(char *var)
{
	int		i;
	char	*env_name;
	char	*var_name;

	i = 0;
	while (env_cp[i] != NULL)
	{
		env_name = ft_find_char(env_cp[i], '=');
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

void	ft_add_var(char *var)
{
	int		i;

	i = 0;
	while (env_cp[i] != NULL)
		i++;
	if (ft_strchr_b(var, '=') == 0)
		env_cp[i] = ft_strjoin(var, "=");
	env_cp[i + 1] = NULL;
}

int		find_var(char *var)
{
	int		i;
	char	*ename;
	char	*vname;

	i = 0;
	vname = ft_find_char(var, '=');
	while (env_cp[i] != NULL)
	{
		ename = ft_find_char(env_cp[i], '=');
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

void	change_line(char *var, int i)
{
	free(env_cp[i]);
	env_cp[i] = ft_strdup(var);
}
