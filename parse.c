/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:31:17 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/09 18:12:16 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    parse_flags(t_params *p)
{
    while (*(p->str) == '0' || *(p->str) == '-')
    {
        if (*(p->str) == '-')
            p->minus = 1;
        else
            p->zero = 1;
        p->str++;
    }
    if (p->minus)
        p->zero = 0;
}

void    parse_width(t_params *p)
{
    if (*(p->str) == '*')
    {
        p->str++;
        p->width = va_arg(p->va, int);
        if (p->width < 0)
        {
            p->width = -p->width;
            p->minus = 1;
            p->zero = 0;
        }
    }
    else
        while (ft_isdigit((int)(*(p->str))))
        {
            p->width *= 10;
            p->width += *(p->str) - '0';
            p->str++;
        }
}

void    parse_prec(t_params *p)
{
    if (*(p->str) == '.')
    {
        p->prec = 1;
        p->str++;
        if (*(p->str) == '*')
        {
            p->str++;
            p->prec_val = va_arg(p->va, int);
            if (p->prec_val < 0)
            {
                p->prec = 0;
                p->prec_val = 0;
            }
        }
        else
            while (*(p->str) >= '0' && *(p->str) <= '9')
            {
		    	p->prec_val *= 10;
		    	p->prec_val += *(p->str) - '0';
		    	p->str++;
		    }
    }
}

void    parse_type(t_params *p)
{
    if (ft_strchr("cspdiuxX%%", *(p->str)))
    {
        p->type = *(p->str);
        p->str++;
    }
    if (p->prec)
        p->zero = 0;
}
