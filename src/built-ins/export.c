/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:32 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/16 18:21:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *	@brief set the export attribute for variables
*/
void	export(char *str)
{
	t_envp		*shell;
	char		*var_value;
	char		*var_name;
	int			i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i] || !str[i + 1] || i == 0)
		return ;
	shell = get_env_struct();
	var_name = ft_substr(str, 0, i);
	var_value = ft_substr(str, i + 1, ft_strlen(str)
										- (ft_strlen(var_name) + 1));
	shell->set(var_name, var_value);
	free(var_name);
	free(var_value);
}