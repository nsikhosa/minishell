/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:50:10 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/10 14:02:57 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*temp;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (!(temp = (char *)malloc(sizeof(*temp) * (ft_strlen(s) + 1))))
		return (NULL);
	temp = ft_strdup(s);
	while (temp[i] == ' ' || temp[i] == '\t' || temp[i] == '\n')
		i++;
	temp = ft_strcpy(temp, temp + i);
	i = ft_strlen(temp) - 1;
	while ((temp[i] == ' ' || temp[i] == '\n' || temp[i] == '\t') && i >= 0)
	{
		temp[i] = '\0';
		i--;
	}
	res = ft_strdup(temp);
	free(temp);
	return (res);
}
