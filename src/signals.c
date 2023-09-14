/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:56:23 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/14 16:27:39 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <sys/types.h>
#include <signal.h>
#include <termios.h>

/**
 * 	Work in progress
 * 	CTRL + C = SIGINT (Partialy done)
 * 	CTRL + \ = SIGQUIT (Done)
 * 	CTRL + D = EOF (Missing)
**/
static void	sighandler(int signal)
{
	//	wait pid for pipe
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		// rl_replace_line("", 0);
		// rl_on_new_line();
		// rl_redisplay();
		exit(0);
		return ;
	}
	
}
/**
 * @brief defines signal behaviour
*/
void	set_signals()
{
	struct sigaction	sig_c;
	struct sigaction	sig_d;

	sig_c.sa_handler = sighandler;
	sig_d.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig_c, NULL);
	sigaction(SIGQUIT, &sig_d, NULL);
}