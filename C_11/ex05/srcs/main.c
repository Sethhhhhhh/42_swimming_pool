/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 02:09:18 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/22 21:26:54 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		neg;
	int		sum;

	i = 0;
	neg = 1;
	sum = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum * neg);
}

int		ft_get_result(int first, int second, char sign)
{
	if (sign == '+')
		return (first + second);
	else if (sign == '-')
		return (first - second);
	else if (sign == '/')
		return (first / second);
	else if (sign == '*')
		return (first * second);
	else if (sign == '%')
		return (first % second);
	return (0);
}

int		main(int argc, char **argv)
{
	int		first;
	int		second;
	char	sign;

	if (argc == 4)
	{
		first = ft_atoi(argv[1]);
		second = ft_atoi(argv[3]);
		sign = argv[2][0];
		if (second == 0 && (sign == '/' || sign == '%'))
		{
			if (sign == '/')
				ft_putstr("Stop : division by zero");
			else if (sign == '%')
				ft_putstr("Stop : modulo by zero");
			putchar('\n');
			return (0);
		}
		ft_putnbr(ft_get_result(first, second, sign));
		putchar('\n');
	}
	return (0);
}
