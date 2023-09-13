/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:56:23 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/13 20:10:57 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <sys/types.h>
#include <signal.h>
#include <termios.h>

/**
 * 	Work in progress
 * 	SIGINT = CTRL + C
 * 	SIGQUIT = CTRL + "\"
**/
void	sighandler(int signal)
{
	printf("%d\n",signal);
	if (signal == SIGINT)
	{
		exit(0);
		return ;
	}
	else if (signal == SIGQUIT)
		write(1, "\n", 1);
	
}

void	set_signals()
{
	struct sigaction	sa_signal;


	sa_signal.sa_handler = sighandler;
	sigemptyset(&sa_signal.sa_mask);
	sa_signal.sa_flags = 0;
	// sa_signal.sa_flags = SA_SIGINFO;
	// sa_signal.sa_sigaction = sighandler;
	sigaction(SIGQUIT, &sa_signal, NULL);
	sigaction(SIGINT, &sa_signal, NULL);
}