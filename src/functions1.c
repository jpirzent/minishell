/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 07:17:43 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/26 11:53:40 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_str(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\"')
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar(' ');
}

void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void	ft_exit(char *line, char **split)
{
	ft_strdel(&line);
	ft_freetab(split);
	ft_freetab(env_cp);
//	ft_printf("exiting\n");
//	sleep(10);
	exit(0);
}