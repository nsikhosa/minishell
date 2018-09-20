/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:44:20 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/10/03 09:43:08 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h>
# include <sys/wait.h>
# include "libftSub/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct	s_shell
{
	char		**env;
	char		*old_path;
	char		*pwd;
	char		*home;
	char		*user;
	int			i;
	char		*tmp;
	char		*tm;
	char		**tmp2;
	int			exit_code;
}				t_shell;

t_shell			g_shell;

void			init(t_shell *s);
void			ft_echo(char **s, t_shell *sh);
char			*getpath(char **s);
char			*path(char *p, char *cmd);
void			exec_sys(char **cmd, t_shell *s);
void			ft_cd(char *dir, t_shell *sh);
void			set_pwd(t_shell *sh);
int				file_exist(char *filename);
void			display_env(t_shell *sh);
void			ft_unsetenv(t_shell *sh, char *val);
void			ft_setenv(t_shell *sh, char *en, char *val);
void			free_join(char **holder, char *s1, char *s2);
void			free_duplicate(char **holder, char *s);
int				free_args(char **arr);
void			ft_free(char *s);
void			free_struct(t_shell *sh, char **args);
void			signal_handler(int signo);
int				env_found(t_shell *sh, char *val);
void			shell_pwd(t_shell *s);
void			prompt_signal(int signo);

#endif
