/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 23:02:39 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 07:52:12 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	size(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_code		sh_builtin_unsetenv(char ***env, char **args)
{
	unsigned int	i;
	unsigned int	j;
	char			**new;

	if (!*args)
		return (C_NOARG);
	if (!ft_getenv(*env, *args))
		return (C_NOVAL);
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (size(*env) - 1))))
		return (C_ALLOC);
	i = 0;
	j = 0;
	while ((*env)[i])
	{
		if ('=' == ft_strcmp((*env)[i], *args))
			i++;
		if ((*env)[i])
			new[j++] = ft_strdup((*env)[i++]);
	}
	new[j] = NULL;
	sh_tab_swap(env, &new);
	sh_tab_free(new);
	return (C_OK);
}
