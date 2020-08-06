/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 03:28:58 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/08 06:10:00 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validbase(char *base)
{
	int i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
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

int	ft_getindexbase(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	sum;
	int base_len;

	if (!ft_validbase(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 0;
	neg = 1;
	sum = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (ft_getindexbase(str[i], base) != -1)
	{
		sum = (sum * base_len) + ft_getindexbase(str[i], base);
		i++;
	}
	return (sum * neg);
}
