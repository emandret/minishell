/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:40:35 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 08:41:36 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabswap(char ***t1, char ***t2)
{
	char	**tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
