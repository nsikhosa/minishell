/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:05:54 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 09:55:42 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		exec_cmd(char **cmd, t_shell *s)
{
	if (ft_strcmp("echo", cmd[0]) == 0)
		ft_echo(cmd, s);
	else if (ft_strcmp("env", cmd[0]) == 0)
		display_env(s);
	else if (ft_strcmp("unsetenv", cmd[0]) == 0)
		ft_unsetenv(s, cmd[1]);
	else if (ft_strcmp("setenv", cmd[0]) == 0)
		ft_setenv(s, cmd[1], cmd[2]);
	else if (ft_strcmp("cd", cmd[0]) == 0)
		ft_cd(cmd[1], s);
	else
		exec_sys(cmd, s);
	free_args(cmd);
}

void			shell_pwd(t_shell *s)
{
	int i;

	i = 0;
	while (s->home[i] && (s->home[i] == s->pwd[i]))
		i++;
	if (!ft_strlen(&(s->pwd[i])))
		ft_putstr("~");
	else
	{
		if (i == 1)
			ft_putstr(&(s->pwd[i]));
		else
			ft_putstr(&(s->pwd[i + 1]));
	}
}

void			prompt(t_shell *sh, char ***multi)
{
	signal(SIGINT, prompt_signal);
	ft_putstr(sh->user);
	ft_putchar(':');
	shell_pwd(sh);
	ft_putstr("$ ");
	get_next_line(0, &sh->tmp);
	sh->tm = ft_strtrim(sh->tmp);
	ft_free(sh->tmp);
	*multi = ft_shellsplit(sh->tm, ';');
	ft_free(sh->tm);
}

static int		command(char ***args, char *s, t_shell *sh, char **m)
{
	if (ft_strlen(s))
	{
		*args = ft_shellsplit(s, ' ');
		if (ft_strcmp(*args[0], "exit") == 0)
		{
			free_args(m);
			free_struct(sh, *args);
			return (1);
		}
		exec_cmd(*args, sh);
		set_pwd(sh);
	}
	return (0);
}

int				main(void)
{
	char	**args;
	char	**multi;

	init(&g_shell);
	while (1)
	{
		prompt(&g_shell, &multi);
		g_shell.i = 0;
		while (multi[g_shell.i])
		{
			if (command(&args, multi[g_shell.i], &g_shell, multi))
				return (0);
			g_shell.i++;
		}
		free_args(multi);
	}
	return (0);
}
