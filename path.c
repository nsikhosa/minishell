/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:29:57 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/26 08:09:46 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			file_exist(char *filename)
{
	struct stat		buffer;

	return ((stat(filename, &buffer) == 0));
}

char		*getpath(char **s)
{
	int		i;
	char	*tmp;
	char	*ret;

	i = 0;
	while (s[i])
	{
		if (ft_strncmp("PATH=", s[i], 5) == 0)
		{
			tmp = malloc(sizeof(char) * (ft_strlen(s[i])));
			tmp = ft_strcpy(tmp, s[i]);
			ret = ft_strsub(tmp, 5, ft_strlen(tmp));
			ft_strdel(&tmp);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char		*path(char *p, char *cmd)
{
	char	**tmp;
	char	*t;
	char	*f;
	int		i;

	i = 0;
	if (!p)
		return (ft_strdup(cmd));
	tmp = ft_strsplit(p, ':');
	ft_strdel(&p);
	while (tmp[i])
	{
		f = ft_strjoin(tmp[i], "/");
		t = ft_strjoin(f, cmd);
		free(f);
		if (file_exist(t))
		{
			free_args(tmp);
			return (t);
		}
		ft_strdel(&t);
		i++;
	}
	free_args(tmp);
	return (ft_strdup(cmd));
}
