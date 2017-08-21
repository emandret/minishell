/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:32:41 by emandret          #+#    #+#             */
/*   Updated: 2017/04/23 13:03:33 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_TYPES_H
# define PF_TYPES_H

# include "../../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

# define CONVERSION_NUMBER 16
# define BUFF_SIZE 1024

# define LONG_MIN -9223372036854775807
# define LONG_MAX 9223372036854775807

typedef struct	s_flags
{
	t_bool		convert;
	t_bool		zero_padding;
	t_bool		space_right;
	t_bool		space_left;
	t_bool		enforce_sign;
}				t_flags;

typedef enum	e_modifier
{
	M_NONE,
	H,
	HH,
	L,
	LL,
	J,
	Z
}				t_modifier;

typedef enum	e_conversion
{
	C_NONE,
	ESC,
	S,
	SS,
	P,
	D,
	DD,
	I,
	O,
	OO,
	U,
	UU,
	X,
	XX,
	C,
	CC
}				t_conversion;

typedef struct	s_format
{
	t_flags		flags;
	int			min_field;
	t_bool		has_precision;
	int			precision;
	t_modifier	modifier;
	char		conversion;
}				t_format;

typedef struct	s_buffer
{
	char		s[BUFF_SIZE];
	int			i;
	int			ret;
}				t_buffer;

typedef void	(*t_handler)(t_buffer *buffer, t_format *format, va_list ap);

#endif
