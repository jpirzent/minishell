/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/13 14:55:18 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char	**line;
	int		stts;

	if (argc != 1 && ft_strequ(argv[0], "minishell"))
		ft_printf("something went wrong\n");
	stts = 1;
	line = ft_memalloc(sizeof(char **));
	print_start();
	ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	while (stts)
	{
		stts = get_next_line(0, line);
		print_line(line, envp);
		ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	}
}