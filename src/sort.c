#include "../include/minishell.h"

/**
 * 
 * 	THIS WASN'T TESTED AND MAY NOT WORK
 * 
*/

static void printcontent(void *content)
{
	printf("%s", (char *)content);
}

void	lst_insert_before(t_env_var *lst, t_env_var *new)
{
	new->previous = lst->previous;
	new->next = lst;
	lst->previous->next = new;
	lst->previous = new;
}

void	export_sort_print()
{
	t_envp		*shell;
	t_env_var	*envp_copy;
	t_env_var	*tmp_i;
	t_env_var	*tmp_j;
	int			count;
	int			compare;

	//sort
	count = ft_lstsize(shell->vars);
	shell = get_env_struct();
	envp_copy = ft_lstnew(shell->vars->content);
	tmp_i = envp_copy;
	while (count)
	{
		tmp_j = shell->vars;
		while (tmp_j)
		{
			compare = ft_strncmp(tmp_i->content, tmp_j->content, ft_strlen(tmp_i->content));
			if (compare < 0)
			{
				lst_insert_before(tmp_i, ft_lstnew(tmp_j->content)); // add before tmp_i
				break;
			}
			tmp_j = tmp_j->next;
		}
		if (compare >= 0)
			ft_lstadd_back(&envp_copy, ft_lstnew(tmp_j->content));
		count--;
	}

	//print
	ft_lstiter(envp_copy, printcontent);
	ft_lstclear(&envp_copy, free);
}
