/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 10:31:27 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/08/24 16:06:22 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		charlen(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	len++;
	nb /= 10;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	char	*ret;
	long	nb;
	int		len;

	nb = (long)nbr;
	len = charlen(nb);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	ret[len] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		ret[0] = '-';
	}
	ret[--len] = (nb % 10) + 48;
	nb /= 10;
	while (nb)
	{
		ret[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}
