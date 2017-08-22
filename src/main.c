/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 23:02:39 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 17:23:03 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char		**get_args(char **old_args)
{
	char	*input;
	char	**args;

	if (old_args)
		ft_memdel((void**)&old_args);
	if (get_next_line(0, &input))
	{
		args = NULL;
		if (*input)
			args = ft_split_whitespaces(input);
		ft_memdel((void**)&input);
		return (args);
	}
	return (NULL);
}

static char		*get_expath(char **paths, char *bin)
{
	unsigned int	i;
	char			*expath;

	if (!paths)
		return (NULL);
	if (!access(bin, F_OK | X_OK))
		return (bin);
	i = 0;
	while (paths[i])
	{
		expath = ft_getpath(paths[i], bin);
		if (!access(expath, F_OK | X_OK))
			return (expath);
		i++;
	}
	return (NULL);
}

static t_bool	do_exec(char **env, char **paths, char **args)
{
	char	*expath;
	pid_t	child;

	expath = get_expath(paths, args[0]);
	if (!expath)
	{
		sh_error(args[0], "command not found");
		return (TRUE);
	}
	child = fork();
	if (child == -1)
	{
		sh_error("fork", "failed to create a child process");
		return (FALSE);
	}
	if (child == 0)
		execve(expath, args, env);
	if (child > 0)
		wait(&child);
	return (TRUE);
}

static void		do_prompt(char **env)
{
	char	*user;
	char	cwd[4096];

	if (!(user = ft_getenv(env, "USER")))
		user = "minishell";
	getcwd(cwd, 4095);
	ft_printf("%s:%s $ ", user, ft_strrchr(cwd, '/'));
}

int				main(int ac, char **av, char **ev)
{
	char	**args;
	char	**paths;
	void	**btins;

	(void)ac;
	(void)av;
	ev = ft_tabdup(ev);
	args = NULL;
	paths = sh_get_paths(ev);
	btins = sh_init_builtins();
	while (1)
	{
		do_prompt(ev);
		if ((args = get_args(args)) && *args)
		{
			if (sh_call_builtins(btins, &ev, args))
				continue ;
			if (!do_exec(ev, paths, args))
				return (-1);
		}
	}
	ft_tabfree((void**)&ev);
	ft_tabfree((void**)&paths);
	ft_tabfree((void**)&btins);
	return (0);
}
