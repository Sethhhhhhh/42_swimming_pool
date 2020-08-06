/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:31:44 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/22 20:32:04 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new;

	new = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		new[i] = (*f)(tab[i]);
		i++;
	}
	return (new);
}
