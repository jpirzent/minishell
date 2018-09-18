/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/18 10:17:35 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		cd_noarg(void)
{
	int		i;
	int		k;
	char	*pwd;

	i = find_var("HOME=");
	pwd = get_pwd(env_cp[i]);
	if (chdir(pwd) != 0)
		ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	else
	{
		if ((i = find_var("PWD=")) < 0)
		{
			new_pwd();
			return ;
		}
		if ((k = find_var("OLDPWD=")) < 0)
		{
			new_opwd();
			return ;
		}
		pwd = ft_strjoin("OLDPWD=", get_pwd(env_cp[i]));
		change_line(pwd, k);
		free(pwd);
		if ((k = find_var("HOME=")) < 0)
		{
			no_home();
			return ;
		}
		pwd = ft_strjoin("PWD=", get_pwd(env_cp[k]));
		change_line(pwd, i);
		free(pwd);
	}
}

void		cd_warg(char *cwd)
{
	int		i;
	int		k;
	char	*pwd;
	char	path[256];
	char	*ptr;

	if (chdir(cwd) != 0)
		ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	else
	{
		i = find_var("PWD=");
		k = find_var("OLDPWD=");
		pwd = ft_strjoin("OLDPWD=", get_pwd(env_cp[i]));
		change_line(pwd, k);
		free(pwd);
		ptr = getcwd(path, sizeof(path));
		pwd = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
		change_line(pwd, i);
		free(pwd);
	}
}
