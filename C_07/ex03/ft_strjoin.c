/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:40:18 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/22 12:42:03 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_size(char **strs, char *sep, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (strs[i] && i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	j += (ft_strlen(sep) * (i - 1));
	return (j + 1);
}

int		ft_sep_count(char **strs, int size)
{
	int		i;

	i = 0;
	while (strs[i] && i < size)
		i++;
	return (i - 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		sep_count;

	if (size <= 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	sep_count = ft_sep_count(strs, size);
	if (!(str = (char *)malloc(sizeof(char) * ft_size(strs, sep, size))))
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (strs[i] && i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < sep_count)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
