/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:11:55 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/12 11:19:53 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include "../library/ft_printf/ft_printf.h"
# include "../library/libft/libft.h"

void    print_start(void);
void    print_line(char **line);
void	ft_echo(char **split);

#endif