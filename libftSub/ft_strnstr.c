/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:46:03 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/13 07:19:34 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	if (*little == '\0')
		return ((char*)big);
	l_len = ft_strlen(little);
	while (*big != '\0' && len-- >= l_len)
	{
		if (*big == *little && ft_memcmp(big, little, l_len) == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
