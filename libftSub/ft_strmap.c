/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:44:50 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/09 11:09:21 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*temp;

	if (s && f)
	{
		i = 0;
		temp = (char *)malloc(sizeof(*temp) * (ft_strlen(s) + 1));
		if (!temp)
			return (NULL);
		while (s[i] != '\0')
		{
			temp[i] = f(s[i]);
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
