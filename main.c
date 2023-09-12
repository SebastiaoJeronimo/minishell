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

#include "minishell.h"

void	print_env()
{
    for (int i = 0; get_structure()->env[i] != NULL; i++) {
        printf("%s\n", get_structure()->env[i]);
    }
}

t_shell	*get_structure(void)
{
	static t_shell	shell;

	return (&shell);
}

/**
 * VER LEAKS NO FINAL DO PROGRAMA
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
		exit(0); //free as cenas 
	while (j < i)
	{
		get_structure()->env[j] = ft_strdup(envp[j]); //free as cenas
		j++;
	}
	get_structure()->env[j] = NULL;
}

int	main(int argc, char **argv, char **envp)
{

	// char	*prompt;
	// int 	i = 3;

	initialize_shell(argc, argv, envp);
	print_env();
	printf("%lu\n", sizeof(char *));
	// while (i)
	// {
	// 	prompt = readline("$>");
	// 	printf("GANDA COMMANDO\n");
	// 	add_history(prompt);
	// 	free(prompt);
	// 	i--;
	// }
	// rl_clear_history();
    // for (int i = 0; envp[i] != NULL; i++) PRINTS THE ENVIROMENT VARIABLES
    //     printf("%s\n", envp[i]);
}

ls >out.txt <in1.txt <in2.txt <in3.txt
