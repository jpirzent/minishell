/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:20 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 17:41:18 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_envp(char **envp, char *var)
{
	int		i;
	int		k;
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
			return(1);
		else
			i++;
	}
	free(env_name);
	free(var_name);
	return (0);
}

