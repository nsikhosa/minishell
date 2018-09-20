/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:25:15 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/10 14:54:46 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ch;
	size_t	len;
	char	*temp;

	i = 0;
	ch = (char *)s;
	len = ft_strlen(ch) + 1;
	temp = NULL;
	while (i < len)
	{
		if (ch[i] == (unsigned char)c)
			temp = ch + i;
		i++;
	}
	if (temp != NULL)
		return (temp);
	return (NULL);
}
