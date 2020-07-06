/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:31:27 by jocaille          #+#    #+#             */
/*   Updated: 2020/07/05 17:30:24 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifdef __APPLE__
#  define P_NULL "0x0"
# else
#  define P_NULL "(nil)"
# endif

# define HEXA_L "0123456789abcdef"
# define HEXA_U "0123456789ABCDEF"

typedef struct	s_padd
{
	int		sp;
	int		zeros;
}				t_padd;

typedef struct	s_params
{
	char	*str;
	va_list	va;
	char	type;
	int		minus;
	int		zero;
	int		prec;
	int		prec_val;
	int		width;
	int		len;
}				t_params;

int				ft_printf(const char *format, ...);

void			parse_flags(t_params *p);
void			parse_width(t_params *p);
void			parse_prec(t_params *p);
void			parse_type(t_params *p);

void			print_c(t_params *p, t_padd *padd);
void			print_s(t_params *p, t_padd *padd);
void			print_p(t_params *p, t_padd *padd);
void			print_int(t_params *p, t_padd *padd);
void			print_hexa(t_params *p, t_padd *padd, int maj);
void			print_uint(t_params *p, t_padd *padd);

void			init_params(t_params *p, t_padd *padd);

#endif
