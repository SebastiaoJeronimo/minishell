/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:18:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/11/06 21:30:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/**
 *	@brief checks if there are any quotations left unclosed
 *	@return (0) no quotes left open, (1) open single quote, (2) open double quote
 * 
*/
int	quote_check(const char *str)
{
	int		i;
	bool	dquote;
	bool	squote;

	i = -1;
	dquote = 0;
	squote = 0;
	while (str[++i])
	{
		if (!squote && !dquote)
		{
			if (str[i] == '\"')
				dquote = !dquote;
			else if (str[i] == '\'')
				squote = !squote;
			continue ;	
		}
		if (squote && str[i] == '\'')
			squote = !squote;
		if (dquote && str[i] == '\"')
			dquote = !dquote;
	}
	return (squote + (dquote * 2));
}

char *prompt_trim(const char *prompt)
{
	int	i;
	int	j;
	char *trim;
	char *tmp;
	char *new_prompt;
	
	i = 0;
	j = 0;
	trim = ft_strtrim(prompt, " ");
	tmp = ft_calloc(ft_strlen(trim) + 1, 1);
	while (trim[i])
	{
		while (trim[i] && trim[i] != '\"' && trim[i] != '\'' 
				&& trim[i] != ' ')
			tmp[j++] = trim[i++];
		if (trim[i] && trim[i] == '\"')
		{
			i++;
			while (trim[i] && trim[i] != '\"')
				tmp[j++] = trim[i++];
		}
		else if (trim[i] && trim[i] == '\'')
		{
			i++;
			while (trim[i] && trim[i] != '\'')
				tmp[j++] = trim[i++];
		}
		if(trim[i] == '\"' || trim[i] == '\'')
			i++;
		if (trim[i] && trim[i++] == ' ')
			tmp[j++] = ' ';
		while(trim[i] && trim[i] == ' ')
			i++;
	}
	tmp[j] = '\0';
	new_prompt = ft_strdup(tmp);
	printf("%s\n", new_prompt);
	free(trim);
	free(tmp);
	return (new_prompt);
}

int	prompt_reader(const char *prompt)
{
	char *new_prompt;
	t_prompt *prompt_list;
	
	(void)prompt_list;
	if (quote_check(prompt))
	{
		printf("error: quotes open"); // Error
		return (0);
	}
	new_prompt = prompt_trim(prompt); 
	//prompt_list = split_prompt(new_prompt); // "cd" > "Hello"
	if (new_prompt)
		free(new_prompt);
	return (0);
}

// char *prompt_trim(char *prompt)
// {
// 	int i;

// 	while(prompt[i])
// }

//expand // "$PWD" becomes ./path

