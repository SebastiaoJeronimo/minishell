/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:44:29 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/15 16:15:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_return(int r, char *path)
{
	(void)path;
	// update_env_var("PWD", path);
	if (r < 0) // Fix this
		perror("insert error message here");
}

/**
 * @brief change the working directory
 * @return on sucess, 0 is returned. On error, -1 is returned.
*/
void	cd(char *path)
{
	int		r;
	char	*home;
	
	r = -1;
	if (!path)
	{
		home = find_env_var("HOME", 1);
		r = chdir(home);
		cd_return(r, home);
	}
	if (!*path)
		return ;
	r = chdir(path);
	cd_return(r, path);
}

//	do we have to define tab behaviour?