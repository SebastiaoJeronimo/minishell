/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:42:26 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/14 16:01:08 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief looks for a env variable and returns it
 * @param arg the variable to find
 * @return the variable and its componnents, NULL if can't find
 * @example find_env_var("PATH");
*/
char *find_env_var(char *arg)
{
	int		i;
	char	*var;
	int		var_len;

	i = 0;
	if (!arg)
		return (NULL);
	var = ft_strjoin(arg, "=");
	if (!var)
		return (NULL);
	var_len = ft_strlen(var);
	while (get_structure()->env[i])
	{
		if (!ft_strncmp(var, get_structure()->env[i], var_len))
		{
			free(var);
			return (get_structure()->env[i] + var_len);
		}
		i++;
	}
	free(var);
	return (NULL);
}
