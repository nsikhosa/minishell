/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 08:08:07 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:13:11 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		print_env(char **s, t_shell *sh)
{
	char	*tmp;
	int		i;

	i = 0;
	while (sh->env[i] != NULL)
	{
		if (!ft_strncmp(&s[0][1], &(sh->env[i][0]), ft_strlen(&s[0][1]))
				&& (sh->env[i][ft_strlen(&s[0][1])] == '='))
		{
			tmp = ft_strchr(sh->env[i], '=');
			ft_putstr(&tmp[1]);
		}
		i++;
	}
}

void			ft_echo(char **s, t_shell *sh)
{
	int i;
	int j;

	i = 1;
	while (s[i])
	{
		j = 0;
		if ((s[i][j] == '$') && (s[i][j + 1] == '?'))
			ft_putnbr(WEXITSTATUS(sh->exit_code));
		else if (s[i][j] == '$')
			print_env(&s[i], sh);
		else
		{
			while (s[i][j])
			{
				if ((s[i][j] != '"') && (s[i][j] != '\''))
					ft_putchar(s[i][j]);
				j++;
			}
		}
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
