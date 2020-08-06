/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:29:10 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/21 23:34:27 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_malloc_size(char *str, char *charset)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(charset, str[i]))
			i++;
		while (str[i] && !ft_is_charset(charset, str[i]))
			i++;
		j++;
	}
	return (j);
}

int		ft_strlen(char *str, int i, char *charset)
{
	int j;

	j = 0;
	while (str[i] && !ft_is_charset(charset, str[i]))
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strcpy(char *str, int *i, char *charset)
{
	int		j;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * (ft_strlen(str, *i, charset) + 1));
	j = 0;
	while (str[*i] && !ft_is_charset(charset, str[*i]))
	{
		tab[j] = str[*i];
		j++;
		*i += 1;
	}
	tab[j] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * ft_malloc_size(str, charset) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && !ft_is_charset(charset, str[i]))
		{
			tab[j] = ft_strcpy(str, &i, charset);
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
