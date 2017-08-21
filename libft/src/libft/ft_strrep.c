/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:37:49 by emandret          #+#    #+#             */
/*   Updated: 2017/08/11 14:21:55 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *src, char *in, char *to)
{
	int		count;
	char	*new;
	char	*pos;

	if ((count = ft_strcount(src, in)))
	{
		new = ft_strnew(ft_strlen(src) +
			(ft_strlen(to) * count) - (ft_strlen(in) * count));
		pos = new;
		while (*src)
		{
			while (*src && ft_strstr(src, in))
			{
				pos = ft_strcpy(pos, to);
				pos += ft_strlen(to);
				src += ft_strlen(in);
			}
			*pos = *src;
			pos++;
			src++;
		}
		return (new);
	}
	return (src);
}
