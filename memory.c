/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:31:05 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:09:28 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		free_join(char **holder, char *s1, char *s2)
{
	char	*tmp;

	tmp = *holder;
	*holder = ft_strjoin(s1, s2);
	ft_free(tmp);
}

void		free_duplicate(char **holder, char *s)
{
	char	*tmp;

	tmp = *holder;
	*holder = ft_strdup(s);
	ft_free(tmp);
}

int			free_args(char **arr)
{
	int	i;

	if (arr == NULL)
		return (1);
	i = 0;
	while (arr[i] != NULL)
	{
		ft_free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
	return (1);
}

void		ft_free(char *s)
{
	if (s == NULL)
		return ;
	free(s);
}

void		free_struct(t_shell *sh, char **args)
{
	free_args(args);
	free_args(sh->env);
	ft_free(sh->user);
	ft_free(sh->home);
	ft_free(sh->old_path);
	ft_free(sh->pwd);
}
