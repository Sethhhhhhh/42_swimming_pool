/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:29:52 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/02 00:35:06 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = -1;
	while (++i < size / 2)
	{
		tmp = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = tmp;
	}
}
