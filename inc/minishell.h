/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:11:55 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/14 13:10:04 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include "../library/ft_printf/ft_printf.h"
# include "../library/libft/libft.h"

void    print_start(void);
void    print_line(char **line, char **envp);
void	ft_echo(char **split);
void	ft_env(char **envp);
void	ft_setenv(char **split, char **envp);
void	ft_print_arg(char *arg);
void	ft_add_var(char *var, char **envp);
void	change_line(char *var, char **envp, int i);
void	ft_unsetenv(char **split, char **envp);
void	delete_line(char **envp, int i);
void	ft_pwd(char **split);
void	ft_cd(char **split, char **envp);
void	ft_help(void);

int		find_var(char *var, char **envp);
int		check_envp(char **envp, char *var);

char	*get_pwd(char *hvar);

#endif