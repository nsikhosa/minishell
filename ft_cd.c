/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:54:54 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/10/03 09:51:22 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			set_pwd(t_shell *sh)
{
	sh->pwd = getcwd(sh->pwd, 300);
}

static void		dash(t_shell *s)
{
	int i;

	i = 0;
	while (s->home[i] && (s->home[i] == s->old_path[i]))
		i++;
	if (!ft_strlen(&(s->old_path[i])) || !ft_strcmp(".", s->old_path))
		ft_putstr("~");
	else
	{
		ft_putstr(&(s->old_path[i + 1]));
	}
	ft_putchar('\n');
}

static void		cd_line(char *dir, t_shell *sh)
{
	if (ft_strcmp(dir, "-") == 0)
	{
		chdir(sh->old_path);
		dash(sh);
		free_duplicate(&sh->old_path, sh->pwd);
	}
	else
	{
		if (chdir(dir) == -1)
		{
			ft_putstr("minishell: no file or directory: ");
			ft_putendl(dir);
		}
		else
			free_duplicate(&sh->old_path, sh->pwd);
	}
}

void			ft_cd(char *dir, t_shell *sh)
{
	char	*tmp;

	if (!dir || !ft_strcmp(dir, "--"))
	{
		chdir(sh->home);
		free_duplicate(&sh->old_path, sh->pwd);
	}
	else if (ft_strncmp(dir, "~", 1) == 0)
	{
		tmp = ft_strdup(dir);
		free_join(&tmp, sh->home, &dir[1]);
		if (chdir(tmp) != -1)
			free_duplicate(&sh->old_path, sh->pwd);
		else
		{
			ft_putstr("minishell: no such file or directory: ");
			ft_putendl(dir);
		}
		ft_free(tmp);
	}
	else
		cd_line(dir, sh);
}
