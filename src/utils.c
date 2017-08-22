/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 23:02:39 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 05:53:59 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sh_error(char *name, char *error)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

void	sh_tab_free(char **tab)
{
	unsigned int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		ft_memdel((void**)&tab[i++]);
	ft_memdel((void**)&tab);
}

void	sh_tab_swap(char ***t1, char ***t2)
{
	char	**tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

char	**sh_get_paths(char **env)
{
	char	*path;

	if (!(path = ft_getenv(env, "PATH")))
		path = "/";
	return (ft_strsplit(path, ':'));
}
