/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:33:14 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/07 15:33:14 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief returns a pointer to the static shell struct
*/
t_shell	*get_structure(void)
{
	static t_shell	shell;

	return (&shell);
}

/**
 * @brief free all alocated memory on the t_shell struct
*/
static void	free_env(t_shell *shell)
{
	int		i;

	i = 0;
	if (!shell->env)
		return ;
	while (shell->env[i])
		free(shell->env[i++]);
	free(shell->env);
}

/**
 * @brief allocates envp to the static shell struct
*/
static void	initialize_shell(int argc, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 1)
		exit(0);
	while (envp[i])
		i++;
	get_structure()->env = malloc((i + 1) * sizeof(char *)); //checkar malloc
	if (!get_structure()->env)
		exit(0); //free
	while (j < i)
	{
		get_structure()->env[j] = ft_strdup(envp[j]);
		j++;
	}
	get_structure()->env[j] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	(void)argv;
	prompt = NULL;
	initialize_shell(argc, envp);
	while (1)
	{
		set_signals();
		//insert user from env to prompt
		prompt = readline("$>");
		if (prompt && *prompt)
			add_history(prompt);
		if (!prompt) //check this leak
		{
			printf("exit\n");
			exit(0); // free
		}
		else
		{
			cd(prompt);
			pwd();
			free(prompt);
		}
	}
	free_env(get_structure());
	rl_clear_history();
}
