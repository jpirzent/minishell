/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:15:09 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/13 17:29:04 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/minishell.h>

void	ft_cd(char **split)
{
	if (split[1] == NULL)
	{
		if (chdir("/~") != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
		else
			ft_printf("change successfull\n");
	}
}
