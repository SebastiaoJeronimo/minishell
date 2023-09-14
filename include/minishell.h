/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:33:05 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/07 15:33:05 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_shell
{
	char		  **env;	//to save the environment variables
	int		shell_level;	//to save the shell_level
}			t_shell;

t_shell	*get_structure(void);
void	set_signals();

//	Built-ins

int		cd(char *arg);
void	echo(char *arg);
void	print_env(void);
void	exit_shell(int exit_code);
void	export(void);
void	pwd(void);
void	unset(char *arg);
void	pwd(void);

//	Utils

char *find_env_var(char *arg);

#endif