/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/19 10:58:17 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		cd_noarg(void)
{
	int		i;
	int		k;
	char	path[256];
	char	*pwd;
	char	*ptr;

	if ((i = find_var("HOME=")) < 0)
	{
		ft_printf("\e[1;31mHOME is unset\e[0m\n");
		return ;
	}
	ptr = getcwd(path, sizeof(path));
	pwd = ft_strjoin("OLDPWD=", path);
	if ((k = find_var("OLDPWD=")) < 0)
		ft_add_var(pwd);
	else
		change_line(pwd, k);
	pwd = get_pwd(env_cp[i]);
	if (chdir(pwd) != 0)
		ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
	else
	{
		ptr = getcwd(path, sizeof(path));
		pwd = ft_strjoin("PWD=", path);
		if ((k = find_var("PWD=")) < 0)
			ft_add_var(pwd);
		else
			change_line(pwd, k);
	}

}

void		cd_warg(char *cwd)
{
	int		i;
	char	*pwd;
	char	path[256];
	char	*ptr;

	if (ft_strequ(cwd, "-"))
		cd_oldpwd();
	else
	{
		ptr = getcwd(path, sizeof(path));
		pwd = ft_strjoin("OLDPWD=", path);
		if ((i = find_var("OLDPWD=")) < 0)
			ft_add_var(pwd);
		else
			change_line(pwd, i);
		if (chdir(cwd) != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
		else
		{
			ptr = getcwd(path, sizeof(path));
			pwd = ft_strjoin("PWD=", path);
			if ((i = find_var(pwd)) < 0)
				ft_add_var(pwd);
			else
				change_line(pwd, i);
		}
	}
}

void		cd_oldpwd(void)
{
	int		i;
	char	*pwd;
	char	*tmp;
	char	path[256];
	char	*ptr;

	if ((i = find_var("OLDPWD=")) < 0)
		ft_printf("\e[1;31mOLDPWD is Unset\e[0m\n");
	else
	{
		pwd = get_pwd(env_cp[i]);
		ptr = getcwd(path, sizeof(path));
		tmp = ft_strjoin("OLDPWD=", path);
		change_line(tmp, i);
		if (chdir(pwd) != 0)
			ft_printf("\e[1;31mUnable to open that dir\e[0m\n");
		else
		{
			tmp = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
			if ((i = find_var(tmp)) < 0)
				ft_add_var(tmp);
			else
				change_line(tmp, i);
		}
	}
}