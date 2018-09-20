/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:51:40 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/23 11:09:30 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	display_env(t_shell *sh)
{
	int i;

	i = 0;
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], "OLDPWD=", 7) == 0)
		{
			if (ft_strncmp(sh->old_path, ".", 1) == 0)
				ft_putendl(sh->env[i]);
			else
			{
				ft_putstr("OLDPWD=");
				ft_putendl(sh->old_path);
			}
		}
		else
			ft_putendl(sh->env[i]);
		i++;
	}
}

int		env_found(t_shell *sh, char *val)
{
	int f;
	int i;

	i = 0;
	f = 0;
	while (sh->env[i])
	{
		if ((ft_strncmp(val, sh->env[i], ft_strlen(val)) == 0) &&
				(sh->env[i][ft_strlen(val)] == '='))
		{
			f++;
		}
		i++;
	}
	if (f)
		return (i);
	else
		return (0);
}

void	ft_unsetenv(t_shell *sh, char *val)
{
	int		i;
	int		j;
	char	**tmp;

	if (!val)
	{
		ft_putendl("Please specify the environment to remove");
		return ;
	}
	tmp = (char **)malloc(sizeof(char *) * (env_found(sh, val)));
	i = 0;
	j = 0;
	while (sh->env[i])
	{
		if (!((ft_strncmp(val, sh->env[i], ft_strlen(val)) == 0) &&
					(sh->env[i][ft_strlen(val)] == '=')))
		{
			tmp[j++] = ft_strdup(sh->env[i]);
		}
		i++;
	}
	tmp[j] = NULL;
	free_args(sh->env);
	sh->env = tmp;
}
