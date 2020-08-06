/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:25:36 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/12 11:22:28 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int sum;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	sum = nb;
	while (i < power)
	{
		sum = sum * nb;
		i++;
	}
	return (sum);
}
