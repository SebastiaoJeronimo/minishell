/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:10:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/19 13:45:13 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *	@brief print name of current/working directory
*/
void	pwd(void)
{
	//Check call pwd after PWD unset
	char *pwd;
	
    pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
}
