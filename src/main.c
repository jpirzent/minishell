/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/24 11:10:40 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_sighan(int snum)
{
	if (snum == 2)
		ft_putstr("\n\e[0;35m]===|>\t\e[0;33m");
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
		free(line);
		ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	}
	free(line);
	ft_freetab(env_cp);
}
