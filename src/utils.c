/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:42:26 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/15 18:01:10 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief looks for a env variable and returns it
 * @param arg the variable to find
 * @param flag if 0, the returned pointer includes the variable name, if 1 it doesn't
 * @return pointer to the env variable, NULL if can't find
 * @example find_env_var("PATH");
*/
char	*find_env_var(char *arg, int flag)
{
	t_shell	*shell;
	int		i;
	char	*var;
	int		var_len;

	shell = get_structure();
	i = 0;
	if (!arg)
		return (NULL);
	var = ft_strjoin(arg, "=");
	if (!var)
		return (NULL);
	var_len = ft_strlen(var);
	while (shell->env[i])
	{
		if (!ft_strncmp(var, shell->env[i], var_len))
		{
			if (!flag)
			{
				free(var);
				return (shell->env[i]);
			}
			else
			{
				free(var);
				return (shell->env[i] + var_len);
			}
		}
		i++;
	}
	free(var);
	return (NULL);
}
