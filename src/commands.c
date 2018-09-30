/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:09:07 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/30 14:57:15 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_echo(char **split)
{
	int		i;

	i = 1;
	while (split[i] != NULL)
	{
		if (split[i] == NULL || split[i][0] == 0)
			i++;
		else
		{
			if (split[i][0] == '$')
				print_var(split[i] + 1);
			else
				print_str(split[i]);
			i++;
		}
	}
	ft_putstr("\n");
	ft_freetab(&split);
}

void	ft_env(char **split)
{
	int		i;

	if (split[1] == NULL)
	{
		if (ft_strequ(split[0], "pwd"))
			ft_pwd(split);
		else
		{
			i = 0;
			while (env_cp[i] != NULL)
			{
				ft_printf("\e[0;32m%s\n", env_cp[i]);
				i++;
			}
		}
	}
	ft_freetab(&split);
}

void	ft_setenv(char **split)
{
	int		i;

	i = 0;
	if (check_envp(split[1]) == 1)
	{
		i = find_var(split[1]);
		change_line(split[1], i);
	}
	else
		ft_add_var(split[1]);
	ft_freetab(&split);
}

void	ft_unsetenv(char **split)
{
	int		i;
	char	*var;

	i = 0;
	if (split[1] != NULL)
	{
		var = format_var(split[1]);
		if (check_envp(var) == 1)
		{
			i = find_var(var);
			delete_line(i);
		}
		else
			ft_printf("\e[1;31mNo environment var with that name\n");
		free(var);
	}
	else
		ft_printf("\e[1;31mToo Few Arguments.\nusage:\tunsetenv [var]\n");
	ft_freetab(&split);
}

void	ft_pwd(char **split)
{
	char	pwd[256];
	char	*ptr;

	if (split[1] == NULL)
	{
		ptr = getcwd(pwd, sizeof(pwd));
		ft_printf("%s\n", ptr);
	}
	else
		ft_printf("Too many arguments\n");
}
