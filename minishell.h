#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_shell
{
    char    **env;
}              t_shell;


t_shell      *get_structure(void);


#endif