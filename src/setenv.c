/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:20 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/27 10:45:48 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_envp(char *var)
{
	int		i;
	char	*env_name;
	char	*var_name;

	i = 0;
	var_name = ft_find_char(var, '=');
	while (env_cp[i] != NULL)
	{
		env_name = ft_find_char(env_cp[i], '=');
		if (ft_strequ(env_name, var_name))
		{
			free(env_name);
			free(var_name);
			return (1);
		}
		else
		{
			i++;
			ft_strdel(&env_name);
		}
	}
	free(env_name);
	free(var_name);
	return (0);
}

void	ft_add_var(char *var)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env_cp[i])
		i++;
	tmp = (char **)ft_memalloc(sizeof(char *) * i + 1);
	tmp[i] = NULL;
	tmp[--i] = ft_strdup(var);
	while (i--)
		tmp[i] = ft_strdup(env_cp[i]);
	ft_freetab(env_cp);
	env_cp = tmp;
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
		ft_strdel(&ename);
		i++;
	}
	free(vname);
	free(ename);
	return (-1);
}

void	change_line(char *var, int i)
{
	ft_strdel(&env_cp[i]);
	env_cp[i] = ft_strdup(var);
}
