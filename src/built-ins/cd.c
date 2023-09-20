/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:44:29 by scosta-j          #+#    #+#             */
/*   Updated: 2023/09/20 20:57:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (!home)
			return ;
		r = chdir(home);
	}
	else if (!*path)
		return ;
	// else if (*path == '~')
	// {
	// 	path = ft_strjoin(home, path + 1);
	// 	r = chdir(path);
	// 	free(path);
	// 	if (r < 0)
	// 		perror("insert error message here");
	// }
	else
		r = chdir(path);
	if (r < 0)
	{
		perror(""); // how do i make this work properly?
		return ;
	}
	set_pwd(1);
}

//	do we have to define tab key behaviour?

/**
 * 	CD =============================
 * 
 * 	No args				->	cd to home				DONE
 * 	Empty args			->	do nothing				DONE
 *  Args 				->	cd to arg				DONE
 *	Args.Arg not found	->	error					NOT SIMILAR
 * 	
 * 
 *  HOME not set		->	"~" Doesn't work & no args does nothing
 * 	PWD/OLDPWD not set	->	everything works normally when changing
 * 							directories always updates PWD/OLDPWD
 *  
 *	ATM OLDPWD is not being updated
*/