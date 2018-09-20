/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:31:27 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:04:53 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int size, int new)
{
	void	*nw;

	nw = ft_memalloc(new);
	nw = ft_memcpy(nw, ptr, size);
	free(ptr);
	return (nw);
}
