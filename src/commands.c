/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:09:07 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/17 15:59:39 by jpirzent         ###   ########.fr       */
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
			ft_putstr("\e[0;32m");
			ft_print_arg(split[i]);
			ft_putchar(' ');
			ft_putstr("\e[0m");
			i++;
		}
	}
	ft_putchar('\n');
}

void	ft_env(void)
{
	int		i;

	i = 0;
	while (env_cp[i] != NULL)
	{
		ft_printf("\e[0;32m%s\n", env_cp[i]);
		i++;
	}
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
}

void	ft_unsetenv(char **split)
{
	int		i;

	i = 0;
	if (check_envp(split[1]) == 1)
	{
		i = find_var(split[1]);
		delete_line(i);
	}
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
