/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 05:34:50 by yviavant          #+#    #+#             */
/*   Updated: 2019/08/07 05:10:30 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n != 0 && (*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return (n == 0 ? 0 : (*s1 - *s2));
}
