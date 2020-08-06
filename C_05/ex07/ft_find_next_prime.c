/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:09:47 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/12 11:25:53 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb < 2 || (nb % 2 == 0 && nb != 2))
		return (0);
	i = 3;
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (!ft_is_prime(nb))
		return (ft_find_next_prime(nb + 1));
	return (nb);
}
