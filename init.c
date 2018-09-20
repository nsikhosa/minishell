/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:16:27 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:10:01 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			**dupenv(char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		tmp[i] = ft_strdup(env[i]);
	tmp[i] = NULL;
	return (tmp);
}

void			init(t_shell *s)
{
	extern char		**environ;
	int				i;

	s->env = dupenv(environ);
	s->old_path = ft_strdup(".");
	s->i = 0;
	i = -1;
	while (s->env[++i])
		if (ft_strncmp("HOME=", s->env[i], 5) == 0)
			s->home = ft_strdup(ft_strchr(s->env[i], '=') + 1);
	i = -1;
	while (s->env[++i])
		if (ft_strncmp("PWD=", s->env[i], 4) == 0)
			s->pwd = ft_strdup(ft_strchr(s->env[i], '=') + 1);
	i = -1;
	while (s->env[++i])
		if (ft_strncmp("USER=", s->env[i], 5) == 0)
			s->user = ft_strdup(ft_strchr(s->env[i], '=') + 1);
}

static void		exec_fexists(char **cmd, char *call)
{
	if (file_exist(call))
	{
		ft_putstr("minishell: shell permission denied: ");
		ft_putendl(cmd[0]);
	}
	else
	{
		ft_putstr(cmd[0]);
		ft_putendl(": command not found");
	}
	ft_free(call);
}

void			exec_sys(char **cmd, t_shell *s)
{
	pid_t	child;
	char	*call;
	char	*t;

	t = path(getpath(s->env), cmd[0]);
	call = ft_strdup(t);
	ft_free(t);
	if (access(call, X_OK) == 0)
	{
		signal(2, signal_handler);
		child = fork();
		if (child == 0)
		{
			if (execve(call, cmd, s->env) == -1)
			{
				ft_putstr(cmd[0]);
				ft_putendl(": command not found");
			}
		}
		wait(&s->exit_code);
		ft_free(call);
	}
	else
		exec_fexists(cmd, call);
}
