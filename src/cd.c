/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 23:02:39 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 05:48:13 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_bool	handle_chdir(char ***env, char *dir)
{
	char	cwd[4096];

	if (getcwd(cwd, 4095) && !chdir(dir))
	{
		sh_builtin_setenv(env, (char*[3]){"OLDPWD", cwd, NULL});
		sh_builtin_setenv(env, (char*[3]){"PWD", dir, NULL});
		return (TRUE);
	}
	return (FALSE);
}

static void		handle_shortcuts(char ***env, char ***args)
{
	char	*prev;
	char	*home;

	if ('-' == ***args && (prev = ft_getenv(*env, "OLDPWD")))
	{
		ft_putendl(prev);
		**args = prev;
	}
	if (ft_strchr(**args, '~') && (home = ft_getenv(*env, "HOME")))
		**args = ft_strrep(**args, "~", home);
}

t_code			sh_builtin_cd(char ***env, char **args)
{
	if (!*args)
		return (C_NOARG);
	if (args[1])
		return (C_2MANY);
	handle_shortcuts(env, &args);
	if (handle_chdir(env, *args))
		return (C_OK);
	return (C_NODIR);
}
