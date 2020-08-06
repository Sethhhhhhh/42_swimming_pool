/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:14:13 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/22 07:41:37 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_getindex(char c, char *base);
int				ft_strlen(char *str);
int				ft_power(int n, int p);
char			*ft_itoa_base(long int nbr, char *base, int neg);

int				ft_check_base(char *base)
{
	int				i;
	int				j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '\f' || base[i] == '\t' || base[i] == '\n'
				|| base[i] == '\r' || base[i] == '\v' || base[i] == ' '
				|| base[i] == '+' || base[i] == '-')
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

unsigned int	ft_atoi_base(char *str, char *base, int *size, int *neg)
{
	int				i;
	int				sum;
	int				base_len;

	if (!ft_check_base(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 0;
	sum = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*neg *= -1;
	while (ft_getindex(str[i], base) != -1)
	{
		sum = (sum * base_len) + ft_getindex(str[i], base);
		i++;
	}
	*size = i;
	return (sum);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int		nb;
	int				neg;
	int				size;

	neg = 1;
	nb = ft_atoi_base(nbr, base_from, &size, &neg);
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	return (ft_itoa_base(nb, base_to, neg));
}
