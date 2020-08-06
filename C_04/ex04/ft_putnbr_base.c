/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:39:38 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/08 03:28:28 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_validbase(char *base)
{
	int i;
	int	j;

	if (!(base[0]) || !(base[1]))
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '+'
		|| base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				base_len;
	char			swap[64];
	unsigned int	nb;

	nb = nbr;
	if (ft_validbase(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		base_len = 0;
		while (base[base_len])
			base_len++;
		i = 0;
		while (nb != 0)
		{
			swap[i++] = base[nb % base_len];
			nb /= base_len;
		}
		while (--i >= 0 && swap[i])
			ft_putchar(swap[i]);
	}
}
