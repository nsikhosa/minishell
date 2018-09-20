/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:25:14 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/09/27 08:45:19 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	signal_handler(int signo)
{
	if (signo == 2 || signo == 3)
		ft_putstr("\n");
}

void	prompt_signal(int signo)
{
	if (signo == 2 || signo == 3)
	{
		ft_putendl("\b \b\b \b");
		ft_putstr(g_shell.user);
		ft_putchar(':');
		shell_pwd(&g_shell);
		ft_putstr("$ ");
	}
}
