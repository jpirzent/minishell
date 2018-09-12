# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 13:27:00 by jpirzent          #+#    #+#              #
#    Updated: 2018/09/12 17:33:36 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES =	ft_isalpha.c \
		ft_strtrim.c \
		ft_strequ.c \
		ft_strstr.c \
		ft_putbnbr.c \
		ft_putchex.c \
		ft_strdel.c \
		ft_putcd.c \
		ft_lstnew.c \
		ft_pudec.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_putnbrl.c \
		ft_strchr_b.c \
		ft_strrev.c \
		ft_strncat.c \
		ft_strsub.c \
		ft_memccpy.c \
		ft_strsplit.c \
		ft_memalloc.c \
		ft_strmap.c \
		ft_find_char.c \
		get_next_line.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_striter.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_strmapi.c \
		ft_strncpy.c \
		ft_strlcat.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_putendl.c \
		ft_putstr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_memchr.c \
		ft_memset.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_atoi.c \
		ft_memcmp.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_strcpy.c \
		ft_toupper.c \
		ft_bzero.c \

OBJECT = $(FILES:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJECT)
	@gcc -Wall -Werror -Wextra -I. -c $(FILES)
	@ar rcs $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo "\x1b[31m"MAKING"\x1b[0m" libft.a

$(OBJECT):
	@gcc -Wall -Werror -Wextra -I. -c $(FILES)

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
