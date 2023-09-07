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

// t_shell	*get_structure(void)
// {
// 	return static	t_shell shell;
// }

int	main(void)
{

	char	*prompt;
	int 	i = 3;
	// initialize_shell(argc, argv, envp);
	while (i)
	{
		prompt = readline("$>");
		printf("GANDA COMMANDO\n");
		add_history(prompt);
		free(prompt);
		i--;
	}
	rl_clear_history();
    // for (int i = 0; envp[i] != NULL; i++) PRINTS THE ENVIROMENT VARIABLES
    //     printf("%s\n", envp[i]);
}
