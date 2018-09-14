/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:15:09 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/14 13:11:01 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/minishell.h>

void	ft_cd(char **split, char **envp)
{
	char	*pwd;
	int		i;

	if (split[1] == NULL)
	{
		i = find_var("HOME=", envp);
		pwd = get_pwd(envp[i]);
		ft_printf("%s\n", pwd);
		if (chdir(pwd) != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	}
}

void	ft_help(void)
{
	ft_printf("\e[0;34mSooooo...\nYou need some help to run my programme?\n");
	ft_printf("Functions that work AND how to use them:\n");
	ft_printf("\t\t- echo [strings...]; //print out the strings you give it\n");
	ft_printf("\t\t- env; //shows the elements in the environment\n");
	ft_printf("\t\t- setenv [varname=varvalue]; //allows the user to add or");
	ft_printf(" change existing var in the environment\n");
	ft_printf("\t\t- unsetenv [varname=varvalue]; //to remove a var from the ");
	ft_printf("environment\n");
	ft_printf("\t\t- pwd; //show the current working dir\n");
	ft_printf("The rest does not work\n\e[0m");
}
