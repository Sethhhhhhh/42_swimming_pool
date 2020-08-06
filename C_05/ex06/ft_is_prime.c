/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:27:02 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/12 11:24:35 by yviavant         ###   ########.fr       */
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