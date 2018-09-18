/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:07:38 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/17 16:12:47 by jpirzent         ###   ########.fr       */
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

void	delete_line(int i)
{
	free(env_cp[i]);
	while (env_cp[i + 1] != NULL)
	{
		env_cp[i] = ft_strdup(env_cp[i + 1]);
		free (env_cp[i + 1]);
		i++;
	}
	env_cp[i] = NULL;
}

char	*get_pwd(char *hvar)
{
	int		i;
	int		len;
	int		start;

	i = 0;
	len = 0;
	while (hvar[i] != '=' && hvar[i])
		i++;
	if (hvar[i] == '\0')
		return (NULL);
	start = i + 1;
	while (hvar[i])
	{
		len++;
		i++;
	}
	return (ft_strsub(hvar, start, len));
}
