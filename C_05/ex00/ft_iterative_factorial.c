/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:54:59 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/12 11:21:19 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	sum;
	int	fact;

	if (nb < 0)
		return (0);
	i = 0;
	fact = nb;
	sum = 1;
	while (i++ < nb)
	{
		sum *= fact;
		fact -= 1;
	}
	return (sum);
}
