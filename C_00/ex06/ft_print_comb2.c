/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:00:44 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/01 10:17:39 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int n)
{
	int decade;
	int unit;

	if (n > 9)
	{
		decade = (n / 10) + 48;
		unit = (n % 10) + 48;
		write(1, &decade, 1);
		write(1, &unit, 1);
	}
	else
	{
		n = n + 48;
		write(1, "0", 1);
		write(1, &n, 1);
	}
}

void	ft_print_comb2(void)
{
	int i;
	int o;

	i = -1;
	while (++i <= 99)
	{
		o = i;
		while (++o <= 99)
		{
			ft_putchar(i);
			write(1, " ", 1);
			ft_putchar(o);
			if (i < 98 || o < 99)
				write(1, ", ", 2);
		}
	}
}
