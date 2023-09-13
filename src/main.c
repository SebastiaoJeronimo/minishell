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
 * @brief allocates envp to the static shell struct
*/
void	initialize_shell(int argc, char **argv, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void) argv;
	if (argc != 1)
		exit(0);
	while (envp[i])
		i++;
	get_structure()->env = malloc((i + 1) * sizeof(char *)); //checkar malloc
	if(!get_structure()->env)
		exit(0); //free
	while (j < i)
	{
		get_structure()->env[j] = ft_strdup(envp[j]); //free
		j++;
	}
	get_structure()->env[j] = NULL;
	set_signals();
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	initialize_shell(argc, argv, envp);
	
	while (1)
	{
		prompt = readline("$>");
		if (strlen(prompt) != 0)
			add_history(prompt);
		free(prompt);
	}
}
