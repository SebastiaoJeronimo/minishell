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
 * THIS IS FOR TESTING PURPOSES ONLY
*/
void	simple_prompt_checker(char *prompt)
{
	if (ft_strncmp(prompt, "exit", 4) == 0)
		exit_shell(0);
	else if (ft_strncmp(prompt, "env", 3) == 0)
		print_env();
	else if (ft_strncmp(prompt, "pwd", 3) == 0)
		pwd();
	else if (ft_strncmp(prompt, "cd", 2) == 0)
	{
		if(ft_strlen(prompt) > 2)
			cd(prompt + 3);
		else
			cd(NULL);
	}
	else if (ft_strncmp(prompt, "echo", 4) == 0)
		echo("");
	else if (ft_strncmp(prompt, "export ", 7) == 0)
		export(prompt + 7);
	else if (ft_strncmp(prompt, "unset ", 5) == 0)
		unset(prompt + 6);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	(void)argv;
	if (argc != 1)
		exit(0);
	prompt = NULL;
	init_env(envp);
	while (1)
	{
		set_signals();
		//add env_var "LOGNAME" to the prompt
		prompt = readline("$>");
		if (prompt && *prompt)
			add_history(prompt);
		if (!prompt)
			break ;
		else
		{
			simple_prompt_checker(prompt);
			free(prompt);
		}
	}
	printf("exit\n");
	destroy_env();
	exit(0); // free

	//rl_clear_history();				is this needed?
}
