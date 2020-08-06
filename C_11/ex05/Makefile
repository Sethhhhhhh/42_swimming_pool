#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yviavant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 10:39:36 by yviavant          #+#    #+#              #
#    Updated: 2019/08/22 13:55:02 by yviavant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	do-op

CFLAGS		=	-Wall -Wextra -Werror

DIR_SRCS	=	./srcs/

HEADER		=	./includes/

SRCS		=	$(DIR_SRCS)main.c $(DIR_SRCS)ft_putnbr.c $(DIR_SRCS)ft_putstr.c $(DIR_SRCS)ft_strlen.c

OBJ			=	${SRCS:.c=.o}

.c.o		:
				gcc ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}		:	${OBJ}
				gcc ${OBJ} -o ${NAME}

all			:	${NAME}

clean:
				rm -f ${OBJ}

fclean		:	clean
				rm -f ${NAME}
	
re			:	fclean all

.PHONY		:	all clean fclean
