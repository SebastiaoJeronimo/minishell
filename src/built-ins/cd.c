/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:44:29 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/19 15:33:16 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_return(int r)
{
	// update_env_var("PWD", path);
	if (r < 0) // Fix this
		perror("insert error message here");
}

/**
 * @brief change the working directory
*/
void	cd(char *path)
{
	int		r;
	char	*home;
	t_envp	*shell;

	shell = get_env_struct();
	home = shell->get_value("HOME");
	r = -1;
	if (!path)
	{
		r = chdir(home);
		// shell->set("OLDPWD", shell->get_value("PWD"));
		// shell->set("PWD", home);
		shell->set("PWD", home);
		cd_return(r);
		return ;
	}
	if (!*path)
		return ;
	if (*path == '~')
	{
		path = ft_strjoin(home, path + 1);
		r = chdir(path);
		// shell->set("OLDPWD", shell->get_value("PWD"));
		shell->set("PWD", path);
		free(path);
		cd_return(r);
		return ;
	}
	else
	{
		r = chdir(path);
		shell->set("PWD", path);
		cd_return(r);
		return ;
	}
	perror("insert error message here");
}

//	do we have to define tab key behaviour?