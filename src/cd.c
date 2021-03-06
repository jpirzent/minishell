/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/30 13:38:47 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		change_env(char *varname, char *pwd)
{
	int		i;

	if ((i = find_var(varname)) < 0)
		ft_add_var(pwd);
	else
		change_line(pwd, i);
}

void		cd_noarg(void)
{
	int		i;
	char	path[256];
	char	*pwd;

	if ((i = find_var("HOME=")) < 0)
	{
		ft_printf("\e[1;31mHOME is unset\e[0m\n");
		return ;
	}
	pwd = ft_strjoin("OLDPWD=", getcwd(path, sizeof(path)));
	change_env("OLDPWD=", pwd);
	if (pwd)
		free(pwd);
	pwd = get_pwd(env_cp[i]);
	if (chdir(pwd) != 0)
		ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	else
	{
		if (pwd)
			ft_strdel(&pwd);
		pwd = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
		change_env("PWD=", pwd);
	}
	if (pwd)
		free(pwd);
}

void		cd_warg(char *cwd)
{
	char	*pwd;
	char	path[256];

	if (ft_strequ(cwd, "-"))
		cd_oldpwd();
	else if (cwd[0] == '~')
		cd_change(cwd);
	else
	{
		pwd = ft_strjoin("OLDPWD=", getcwd(path, sizeof(path)));
		change_env("OLDPWD=", pwd);
		if (chdir(cwd) != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
		else
		{
			ft_strdel(&pwd);
			pwd = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
			change_env("PWD=", pwd);
		}
		ft_strdel(&pwd);
	}
}

void		cd_oldpwd(void)
{
	int		i;
	char	*pwd;
	char	*tmp;
	char	path[256];

	if ((i = find_var("OLDPWD=")) < 0)
		ft_printf("\e[1;31mOLDPWD is Unset\e[0m\n");
	else
	{
		pwd = get_pwd(env_cp[i]);
		tmp = ft_strjoin("OLDPWD=", getcwd(path, sizeof(path)));
		change_line(tmp, i);
		if (chdir(pwd) != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
		else
		{
			ft_strdel(&tmp);
			tmp = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
			change_env("PWD=", tmp);
			ft_strdel(&tmp);
		}
		free(pwd);
	}
}

void		cd_change(char *cwd)
{
	int		i;
	char	*pwd;
	char	*cwd1;
	char	path[256];

	if ((i = find_var("HOME=")) < 0)
	{
		ft_printf("\e[1;31mHOME is unset\e[0m\n");
		return ;
	}
	pwd = get_pwd(env_cp[i]);
	cwd1 = ft_strjoin(pwd, cwd + 1);
	ft_strdel(&pwd);
	pwd = ft_strjoin("OLDPWD=", getcwd(path, sizeof(path)));
	change_env("OLDPWD=", pwd);
	if (chdir(cwd1) != 0)
		ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	else
	{
		ft_strdel(&pwd);
		pwd = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
		change_env("PWD=", pwd);
	}
	free(pwd);
	free(cwd1);
}
