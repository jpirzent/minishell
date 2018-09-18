/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:11:55 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/17 16:05:33 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include "../library/ft_printf/ft_printf.h"
# include "../library/libft/libft.h"

char	**env_cp;

void	print_start(void);
void	print_line(char **line);
void	ft_echo(char **split);
void	ft_env(void);
void	ft_setenv(char **split);
void	ft_print_arg(char *arg);
void	ft_add_var(char *var);
void	change_line(char *var, int i);
void	ft_unsetenv(char **split);
void	delete_line(int i);
void	ft_pwd(char **split);
void	ft_cd(char **split);
void	ft_help(void);
void	in_env(char **envp);
void	cd_noarg(void);
void	cd_warg(char *pwd);

int		find_var(char *var);
int		check_envp(char *var);

char	*get_pwd(char *hvar);

#endif
