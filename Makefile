# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 13:08:36 by ngeschwi          #+#    #+#              #
#    Updated: 2021/07/08 12:14:50 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
			sources/ft_init_struct.c \
			sources/ft_start.c \
			sources/ft_get_text_file1.c \
			sources/gnl/gnl.c \
			sources/basic_function/ft_strlen.c \
			sources/basic_function/ft_strdup.c \
			sources/basic_function/ft_strjoin.c

OBJS	= $(SRCS:.c=.o)

NAME	= pipex

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I./includes -o $@ -c $<

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -o $(NAME)

$(OBJS):	includes/pipex.h

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
