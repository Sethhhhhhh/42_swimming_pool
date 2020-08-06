/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:14:23 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/22 07:32:56 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_getindex(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_power(int n, int p)
{
	int result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int		ft_len(long int nbr, int size, int neg)
{
	int			i;

	i = 0;
	if (neg == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long int nbr, char *base, int neg)
{
	char		*sum;
	int			len;
	int			i;

	i = 0;
	len = ft_len(nbr, ft_strlen(base), neg);
	if (!(sum = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	sum[len] = '\0';
	if ((neg == -1 && len == 1) || (len == 0 && neg == 0))
	{
		sum[0] = base[0];
		return (sum);
	}
	neg == -1 ? sum[0] = '-' : 0;
	nbr == 0 ? sum[0] = base[0] : 0;
	nbr == 0 ? sum[1] = '\0' : 0;
	while (nbr > 0)
	{
		sum[(len - (i++) - 1)] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	return (sum);
}
