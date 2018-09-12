/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 12:54:53 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int     main(void)
{
	char	**line;
	int		stts;

	stts = 1;
	line = ft_memalloc(sizeof(char **));
	print_start();
	ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	while (stts)
	{
		stts = get_next_line(0, line);
		print_line(line);
		ft_putstr("\e[0;35m]===|>\t\e[0;33m");
	}
}