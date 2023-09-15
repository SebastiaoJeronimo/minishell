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
	char	**env;									//	to save the environment variables
	int		shell_level;							//	to save the shell_level
}			t_shell;

typedef enum bool
{
	false,
	true
}	t_bool;

// typedef struct s_envp
// {
// 	t_list				**vars;								//  [ ] pointer to var_list
// 	char				**env_array							//	[ ] array with env
// 	t_bool				(*init)(char **envp);				//  [ ] (F) initialize envp
// 	t_env_var			*(*get)(char *name);				//  [ ] (F) get env var struct 
// 	char				*(*get_value)(char *name);			//  [ ] (F) get env var value
// 	void				(*set)(char *name, char *value);	//  [ ] (F) add var to envp
// 	t_bool				(*unset)(char *name);				//  [ ] (F) remove var from envp
// 	char				**(*get_env)(void);					//  [ ] (F)
// 	void				(*print)(void);						//  [ ] (F) print all env vars
// 	t_bool				(*is_set)(char *name);				//  [ ] (F) check if var exists
// 	//t_env_var			*path;								//  [ ] pointer to path
// }				t_envp;

// typedef struct s_env_var
// {
// 	char				*name;								//  env var name
// 	char				*value;								//	env var value
// 	struct s_env_var	*next;								//	pointer to next env var
// }			t_env_var;

t_shell	*get_structure(void);
void	set_signals(void);

//	Built-ins

void	cd(char *path);
void	echo(char *arg);
void	print_env(void);
void	exit_shell(int exit_code);
void	export(void);
void	pwd(void);
void	unset(char *arg);
void	pwd(void);

//	Utils

char	*find_env_var(char *arg, int flag);

//	TODO

// remove_env_var(char *str);
// add_env_var(char *str);
// update_env_var(char *str, char *str);
// realloc_env(void);

#endif