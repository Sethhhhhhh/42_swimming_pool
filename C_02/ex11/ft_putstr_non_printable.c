/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:38:37 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/07 01:48:16 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			if (str[i] < 0)
			{
				ft_putchar(hex[(str[i] + 256) / 16]);
				ft_putchar(hex[(str[i] + 256) % 16]);
			}
			else
			{
				ft_putchar(hex[str[i] / 16]);
				ft_putchar(hex[str[i] % 16]);
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
