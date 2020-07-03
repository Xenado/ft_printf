/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:31:27 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/30 20:57:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define HEXA_L "0123456789abcdef"
# define HEXA_U "0123456789ABCDEF"

typedef struct  s_params
{
    char    *str;
    va_list va;
    char    type;
    int     minus;
    int     zero;
    int     prec;
    int     prec_val;
    int     width;
    int     len;
}               t_params;

int             ft_printf(const char *format, ...);

void            parse_flags(t_params *p);
void            parse_width(t_params *p);
void            parse_prec(t_params *p);
void            parse_type(t_params *p);

void            print_c(t_params *p);
void            print_s(t_params *p);
void            print_p(t_params *p);
void            print_int(t_params *p);
void            print_hexa(t_params *p, int maj);
void            print_uint(t_params *p);

void            init_params(t_params *p);

#endif
