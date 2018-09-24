/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/24 09:37:46 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_sighan(int snum)
{
	if (snum == 2)
		ft_putstr("\n\e[0;35m]===|>\t\e[0;33m");
}

void	ft_inc_shell(void)
{
	int		i;
	int		val;
	char	*var;

	if ((i = find_var("SHLVL=")) < 0)
		ft_add_var("SHLVL=1");
	else
		{
			var = get_pwd(env_cp[i]);
			val = ft_atoi(var);
			val++;
			var = ft_itoa(val);
			var = ft_strjoin("SHLVL=", var);
			change_line(var, i);
		}
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	int		stts;

	if (argc != 1 && ft_strequ(argv[0], "minishell"))
		ft_printf("something went wrong\n");
	stts = 1;
	in_env(envp);
	line = ft_memalloc(sizeof(char *));
	print_start();
	signal(SIGINT, ft_sighan);
	signal(SIGABRT, ft_sighan);
	while (stts)
	{
		stts = get_next_line(0, &line);
		print_line(line);
		//free(line);
		ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	}
}
