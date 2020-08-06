#!/bin/sh

gcc -c -Wall -Wextra -Werror ft_swap.c ft_strlen.c ft_strcmp.c ft_putstr.c ft_putchar.c
ar rc libft.a ft_putchar.o ft_putstr.o ft_swap.o ft_strcmp.o ft_strlen.o
ranlib libft.a
