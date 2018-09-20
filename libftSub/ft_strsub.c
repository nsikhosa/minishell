/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:43:34 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/10 13:29:59 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;
	char	*str;

	str = (char *)s;
	i = 0;
	if (str)
	{
		temp = (char *)malloc(sizeof(*temp) * (len + 1));
		if (!temp)
			return (NULL);
		while (str[start] != '\0' && i < len)
		{
			temp[i] = str[start];
			i++;
			start++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
