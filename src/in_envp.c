/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:13:05 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/24 11:11:55 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	envp_count(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void		in_env(char **envp)
{
	int		i;

	i = 0;
	env_cp = (char **)malloc(sizeof(char *) * (envp_count(envp) + 100));
	while (envp[i])
	{
		if (!(env_cp[i] = ft_strdup(envp[i])))
		{
			ft_printf("something went wrong ?\n");
			exit(0);
		}
		i++;
	}
}
