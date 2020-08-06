/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:49:02 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/17 23:18:31 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexadress(long adress)
{
	char	*hex;
	char	swap[15];
	int		i;

	hex = "0123456789abcdef";
	i = -1;
	while (++i < 15)
	{
		if (adress / 16 >= 0)
		{
			swap[i] = hex[adress % 16];
			adress /= 16;
		}
	}
	i = 15;
	while (--i >= 0)
		ft_putchar(swap[i]);
	write(1, ": ", 2);
}

void	ft_putstr(char *str, int str_len)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (i < str_len)
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
		}
}

void	ft_puthex(char *str, int str_len)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = -1;
	while (++i < 16)
	{
		if (i < str_len)
		{
			if ((str[i] >= 32 && str[i] <= 126))
			{
				ft_putchar(hex[str[i] % 16]);
				ft_putchar(hex[str[i] / 16]);
			}
			else
				write(1, "00", 2);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			ft_putchar(' ');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int number_line;
	int i;
	int str_len;

	if (size <= 0)
		return (addr);
	str_len = 0;
	while (((char *)addr)[str_len] && (unsigned int)str_len < size)
		str_len++;
	number_line = ((str_len - 1) / 16);
	i = -1;
	while (++i < number_line + 1)
	{
		str_len = 0;
		while (((char *)addr)[str_len] && str_len < 16
		&& (unsigned int)str_len < size)
			str_len++;
		size -= str_len;
		ft_puthexadress((long)&addr[i == 0 ? 0 : 1]);
		ft_puthex((char *)addr, str_len);
		ft_putstr((char *)addr, str_len);
		ft_putchar('\n');
		addr += 16;
	}
	return (addr);
}
