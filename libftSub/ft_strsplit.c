/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:16:47 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/07/20 10:51:52 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;

	tab = NULL;
	i = 0;
	if (!s)
		return (NULL);
	len = ft_count((const char*)s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	while (len--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char*)s, 0, ft_word_len((const char*)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_word_len(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
