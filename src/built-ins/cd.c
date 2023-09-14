/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:44:29 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/14 16:45:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief change the working directory
 * @return on sucess, 0 is returned. On error, -1 is returned.
*/
int	cd(char *arg)
{
	int	r;
	
	r = -1;
	if (!arg)
	{
		if (access(find_env_var("HOME"), X_OK) == 0)
			r = chdir(find_env_var("HOME"));
		return (r);
	}
	if (!*arg)
		return (0);
	if (access(arg, X_OK) == 0)
		r = chdir(arg);
	return (r);
	// Need help to handle multiple parameters errors
}

//	do we have to define tab behaviour?