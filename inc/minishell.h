/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 23:02:47 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 05:57:22 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "gnl.h"

/*
** Define the number of builtins supported
*/
# define BUILTINS 6

/*
** Error codes for builtins
*/
typedef enum	e_code
{
	C_OK,
	C_ALLOC,
	C_NODIR,
	C_NOVAL,
	C_NOARG,
	C_2MANY
}				t_code;

/*
** All builtins must have the same declaration
*/
typedef t_code	(*t_builtin)(char ***env, char **args);

/*
** Builtins
*/
t_code			sh_builtin_echo(char ***env, char **args);
t_code			sh_builtin_cd(char ***env, char **args);
t_code			sh_builtin_setenv(char ***env, char **args);
t_code			sh_builtin_unsetenv(char ***env, char **args);
t_code			sh_builtin_env(char ***env, char **args);
t_code			sh_builtin_exit(char ***env, char **args);

/*
** builtins.c
*/
void			**sh_init_builtins(void);
t_bool			sh_call_builtins(void **btins, char ***env, char **args);

/*
** utils.c
*/
void			sh_error(char *name, char *error);
void			sh_tab_free(char **tab);
void			sh_tab_swap(char ***t1, char ***t2);
char			**sh_get_paths(char **env);

#endif
