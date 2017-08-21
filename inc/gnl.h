/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:23:11 by emandret          #+#    #+#             */
/*   Updated: 2017/08/21 23:04:49 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/src/printf/inc/ft_printf.h"

typedef struct		s_this
{
	int				fd;
	char			*left;
	struct s_this	*next;
}					t_this;

int					get_next_line(const int fd, char **line);

#endif
