# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 16:37:20 by jpirzent          #+#    #+#              #
#    Updated: 2018/08/20 16:30:52 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c\
		ft_isalpha.c\
		pr_cprint.c\
		pr_functions.c\
		pr_functions1.c\
		pr_handle.c\
		pr_print.c\
		pr_wchars.c\

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Werror -Wextra -I. -c $(FILES)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[31m"MAKING"\x1b[0m" libftprintf.a

$(OBJ):
	@gcc -Wall -Werror -Wextra -I. -c $(FILES)

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONEY: all clean fclean re

.PRECIOUS := author
