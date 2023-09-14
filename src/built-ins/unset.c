/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:39 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/14 16:49:46 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *	@brief unset values and attributes of variables and functions
*/
void	unset(char *arg)
{
	if (!arg)
	{
		printf("unset: not enough arguments\n");
		return ;
	}
}