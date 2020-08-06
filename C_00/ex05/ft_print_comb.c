/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:24:29 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/01 13:45:04 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_groups(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		ft_print_groups(a, b, c);
		if (c < '9')
			c++;
		else if (c == '9' && b < '8')
		{
			b++;
			c = b + 1;
		}
		else if (c == '9' && b == '8' && a <= '7')
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
	}
}
