/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:08:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/13 19:28:10 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_env();
void	set_env();

void	print_env()
{
	int i;

	i = 0;
	while (get_structure()->env[i])
		printf("%s\n", get_structure()->env[i++]);
}