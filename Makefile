# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 12:00:30 by jpirzent          #+#    #+#              #
#    Updated: 2018/09/30 12:51:07 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = minishell

# PATHS #
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/
LIB_PATH = ./library/libft/
PRF_PATH = ./library/ft_printf/


# FILES #
SRC_FILES = commands.c\
			main.c\
			print_line.c\
			print_start.c\
			functions.c\
			setenv.c\
			commands1.c\
			in_envp.c\
			cd.c\
			env_cmd.c\
			functions1.c\

OBJ_FILES = $(SRC_FILES:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))


# COMPILE #
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

LIBF = $(LIB_PATH)libft.a
PRF = $(PRF_PATH)libftprintf.a

$(NAME): temp $(OBJ)
	@make -C $(LIB_PATH)
	@make -C $(PRF_PATH)
	@$(CC) -o $@ $(LIBF) $(PRF) $(OBJ)
	@echo "\033[92m"---COMPILED SUCCESFULLY---"\033[0m"


# MAKE COMMANDS #
all: $(NAME)

temp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I $(INC_PATH) -o $@ -c $<
	@echo "\x1b[31m"MAKING"\x1b[0m" $@

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\x1b[31m"CLEANING"\x1b[0m" ./objs/

fclean: clean fcleanlib
	@/bin/rm -rf $(NAME)
	@echo "\x1b[31m"REMOVING"\x1b[0m" $(NAME)

cleanlib:
	@make clean -C $(LIB_PATH)
	@make clean -C $(PRF_PATH)
	@echo "\x1b[31m"CLEANING"\x1b[0m" ./libft/

fcleanlib: cleanlib
	@make fclean -C $(LIB_PATH)
	@make fclean -C $(PRF_PATH)
	@echo "\x1b[31m"REMOVING"\x1b[0m" libft.a AND libftprintf.a

re: fclean fcleanlib all

.PHONY: re clean fclean all
