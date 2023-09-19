/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:35:44 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/19 16:16:48 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief returns a pointer to the static shell struct
*/
t_envp	*get_env_struct(void)
{
	static t_envp shell;

	return (&shell);
}

/**
 * @brief creates a linked list with all existing env variables and stores it
 * 		  on the static shell struct
*/
void	create_env_list(char **envp)
{
	t_envp	*shell;
	int		i;

	shell = get_env_struct();
	i = 0;
	if (!envp)
		return ;
	shell->vars = ft_lstnew(strdup(envp[i]));
	while (envp[++i])
		ft_lstadd_back(&shell->vars, ft_lstnew(strdup(envp[i])));
}

void	create_env_array()
{
	t_envp		*shell;
	t_env_var	*tmp;
	int			env_len;
	int			i;

	shell = get_env_struct();
	if (shell->vars)
		return ;
	tmp = shell->vars;
	i = 0;
	env_len = ft_lstsize(shell->vars);
	if (shell->env_array)
		destroy_env_array();
	shell->env_array = malloc((env_len + 1) * sizeof(char *));
	if (!shell->env_array)
		exit(0);
	while (tmp)
	{
		shell->env_array[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	shell->env_array[i] = NULL;
}

void	destroy_env_array()
{
	t_envp	*shell;
	int		i;

	shell = get_env_struct();
	i = 0;
	if (!shell->env_array)
		return ;
	while (shell->env_array[i])
		free(shell->env_array[i++]);
	free(shell->env_array);
}

/**
 * @brief initializes the env struct (to be run at the begining of
 * 		  the program)
*/
void	init_env(char **envp)
{
	t_envp		*shell;

	shell = get_env_struct();
	shell->env_array = NULL;
	shell->get = get_env_var;
	shell->get_value = get_env_var_value;
	shell->set = set_env_var;
	shell->unset = unset_env_var;
	shell->print = print_env;
	shell->destroy = destroy_env;

	create_env_list(envp);
}

/**
 * @brief frees everything
*/
void	destroy_env()
{
	t_envp	*shell;

	shell = get_env_struct();
	if (shell->vars)
		ft_lstclear(&shell->vars, free);
	// if (shell->env_array)
	// 	destroy_env_array();
	}


/**
 * @brief unsets the env variable given
 * @param name the variable to unset
 * @example unset_env_var("PATH");
*/
void	unset_env_var(const char *name)
{
	t_envp		*shell;
	t_env_var	*current;
	char		*var_name;

	shell = get_env_struct();
	if (!name || !shell->vars)
		return ;
	current = shell->vars;
	var_name = ft_strjoin(name, "=");
	if (!var_name)
		return ;
	while (current)
	{
		if (!ft_strncmp(var_name, current->content, ft_strlen(var_name)))
		{
			current->previous->next = current->next;
			if (current->next)
				current->next->previous = current->previous;
			ft_lstdelone(current, free);
			return ;
		}
		current = current->next;
	}
}

/**
 * @brief sets the env variable given
 * @param name the variable to set
 * @example set_env_var("PATH", "/bin:/usr/bin");
*/
void	set_env_var(const char *name, const char *value)
{
	t_envp		*shell;
	t_env_var	*current;
	char 		*var_name;

	if (!name || !value)
		return ;
	shell = get_env_struct();
	current = get_env_var(name);
	var_name = ft_strjoin(name, "=");
	if (!current)
		ft_lstadd_back(&shell->vars, ft_lstnew(ft_strjoin(var_name, value)));
	else
	{
		free(current->content);
		current->content = ft_strjoin(var_name, value);
	}
	free(var_name);
	//  do nothing if var and value are the same as existing one
}

/**
 * @brief looks for a env variable and returns it
 * @param str the variable to find
 * @return pointer to the env variable, NULL if can't find
 * @example find_env_var("PATH");
*/
t_env_var	*get_env_var(const char *str)
{
	t_envp		*shell;
	t_env_var	*current;
	char		*var_name;

	if (!str)
		return (NULL);
	shell = get_env_struct();
	current = shell->vars;
	var_name = ft_strjoin(str, "=");
	if (!var_name)
		return (NULL);
	while (current)
	{
		if (!ft_strncmp(var_name, current->content, ft_strlen(var_name)))
		{
			free(var_name);
			return (current);
		}
		current = current->next;
	}
	free(var_name);
	return (NULL);
}

/**
 * @brief looks for a env variable and returns it's value
 * @param str the variable to get the value
 * @return pointer to the variable's value, NULL if can't find it
 * @example get_env_var_value("PATH");
*/
char	*get_env_var_value(const char *str)
{
	int		i;
	char	*var;

	i = 0;
	if (!str)
		return (NULL);
	var = get_env_var(str)->content;
	if (!var)
		return (NULL);
	var = ft_strchr(var, '=') + 1;
	if (!var[i])
		return (NULL);
	return (&var[i]);
}
