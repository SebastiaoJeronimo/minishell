/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/13 21:13:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *	@brief exit the minishell
 *	-1 -128 kernel stopped the program 
 *	0 sucessful
 *	1-127 error
*/
void	exit_shell(int exit_code)
{
	int i = exit_code;
	(void)i;
}