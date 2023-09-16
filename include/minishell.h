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

# define _XOPEN_SOURCE 700							// Dunno what this is but now sigaction works on my home pc
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef enum bool
{
	false,
	true
}	t_bool;

typedef struct s_envp
{
	t_env_var			*vars;											//  [x] pointer to var_list
	char				**env_array;									//	[ ] array with env
	t_env_var			*(*get)(const char *name);						//  [x] (F) get env var struct 
	char				*(*get_value)(const char *name);				//  [x] (F) get env var value
	void				(*set)(const char *name, const char *value);	//  [x] (F) add var to envp
	void				(*unset)(const char *name);						//  [ ] (F) remove var from envp
	char				**(*get_env)(void);								//  [ ] (F)
	void				(*print)(void);									//  [x] (F) print all env vars
	t_bool				(*is_set)(char *name);							//  [ ] (F) check if var exists
	//t_env_var			*path;											//  [ ] pointer to path
}				t_envp;

t_envp	*get_env_struct(void);
void	set_signals(void);

//	Built-ins

void	cd(char *path);
void	echo(char *arg);
void	print_env(void);
void	exit_shell(int exit_code);
void	export(char *str);
void	pwd(void);
void	unset(char *arg);
void	pwd(void);

//	Utils

//	_encv.c

void		init_env(char **envp);
void		unset_env_var(const char *name);
void		set_env_var(const char *name, const char *value);
t_env_var	*get_env_var(const char *str);
char		*get_env_var_value(const char *str);

#endif