/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:32:15 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/05 20:58:18 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	i = -1;
	while (str[++i])
	{
		if ((str[i] > '9' && str[i] < 'a') || str[i] > 'z' || str[i] < '0')
		{
			j = i + 1;
			if (str[j] >= 'a' && str[j] <= 'z')
			{
				str[j] = str[j] - 32;
				i++;
			}
		}
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	return (str);
}
