# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yviavant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 10:39:36 by yviavant          #+#    #+#              #
#    Updated: 2019/08/20 20:17:06 by yviavant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CFLAGS		=	-Wall -Wextra -Werror

DIR_SRCS	=	./srcs/

HEADER		=	./includes/

SRCS		=	$(DIR_SRCS)ft_putchar.c $(DIR_SRCS)ft_swap.c $(DIR_SRCS)ft_putstr.c $(DIR_SRCS)ft_strlen.c $(DIR_SRCS)ft_strcmp.c

OBJ			=	${SRCS:.c=.o}

.c.o		:
				gcc ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}		:	${OBJ}
				ar rc ${NAME} ${OBJ}

all			:	${NAME}

clean:
				rm -f ${OBJ}

fclean		:	clean
				rm -f ${NAME}
	
re			:	fclean all

.PHONY		:	all clean fclean
