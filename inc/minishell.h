/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:11:55 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 17:42:12 by jpirzent         ###   ########.fr       */
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

#endif