/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:08:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/20 20:29:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *	@brief print enviroment variables
*/
void	print_env(void)
{
	t_envp		*shell;
	t_env_var	*current;

	shell = get_env_struct();
	current = shell->vars;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}
