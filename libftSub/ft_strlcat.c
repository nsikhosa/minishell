/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:07:41 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/08/08 10:22:57 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;
	char	*s1;

	s1 = (char *)src;
	len = 0;
	while (len < size && *dst && *(dst++))
		len++;
	n = size - len;
	if (!n)
		return (len + ft_strlen(s1));
	while (*src)
	{
		if (n != 1)
		{
			*(dst++) = *src;
			n--;
		}
		src++;
		len++;
	}
	*dst = '\0';
	return (len);
}
