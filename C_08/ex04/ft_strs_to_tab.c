/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 02:21:52 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/14 02:34:22 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char			*dest;
	int				i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tb;

	tb = (struct s_stock_str *)malloc(sizeof(*tb) * (ac + 1));
	if (tb == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tb[i].size = ft_strlen(av[i]);
		tb[i].str = ft_strdup(av[i]);
		tb[i].copy = ft_strdup(av[i]);
		i++;
	}
	tb[i].str = 0;
	tb[i].size = 0;
	tb[i].copy = 0;
	return (tb);
}
