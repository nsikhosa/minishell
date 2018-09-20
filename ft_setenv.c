/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:46:16 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:12:02 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int			get_pos(char *str, t_shell *sh)
{
	int		i;
	char	*temp;

	i = -1;
	while (sh->env[++i])
	{
		temp = ft_strjoin(str, "=");
		if (ft_strstartswith(sh->env[i], temp))
		{
			free(temp);
			return (i);
		}
		free(temp);
	}
	return (i);
}

static char			**mem_realloc(int new_size, t_shell *sh)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size));
	i = -1;
	while (sh->env[++i] && i < new_size)
	{
		new[i] = ft_strdup(sh->env[i]);
		free(sh->env[i]);
	}
	free(sh->env);
	return (new);
}

static void			set_env(char *key, char *value, t_shell *sh)
{
	int		pos;
	char	*temp;

	pos = get_pos(key, sh);
	temp = ft_strjoin("=", value);
	if (sh->env[pos])
	{
		free(sh->env[pos]);
		if (value)
			sh->env[pos] = ft_strjoin(key, temp);
		else
			sh->env[pos] = ft_strjoin(key, "=");
	}
	else
	{
		sh->env = mem_realloc(pos + 1, sh);
		if (value)
			sh->env[pos] = ft_strjoin(key, temp);
		else
			sh->env[pos] = ft_strjoin(key, "=");
	}
	free(temp);
}

void				ft_setenv(t_shell *sh, char *en, char *val)
{
	if (!en)
		ft_putendl("Syntax error");
	else
		set_env(en, val, sh);
}
