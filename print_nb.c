/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:47:34 by jocaille          #+#    #+#             */
/*   Updated: 2020/07/03 17:40:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void display_nb(t_params *p, char *str, int zeros, int sp, int neg)
{
    p->len = zeros > 0 ? p->len + zeros : p->len;
    p->len = sp > 0 ? p->len + sp : p->len;
    p->len += ft_strlen(str);
    if (p->zero || p->minus)
    {
        if (neg)
        {
            ft_putchar_fd(*str++, 1);
        }
        while (zeros-- > 0)
            ft_putchar_fd('0', 1);
        ft_putstr_fd(str, 1);
        while (sp-- >0)
            ft_putchar_fd(' ', 1);
    }
    else
    {
        while (sp-- >0)
            ft_putchar_fd(' ', 1);
        if (neg)
            ft_putchar_fd(*str++, 1);
        while (zeros-- > 0)
            ft_putchar_fd('0', 1);
        ft_putstr_fd(str, 1);
    }
}

static void pre_display(t_params *p, char *str, int neg)
{
    int     zeros;
    int     sp;
    int     len;

    len = ft_strlen(str);
    zeros = 0;
    if (p->zero && p->width > len)
        zeros = p->width - len;
    if (p->prec && p->prec_val > len - neg)
        zeros = p->prec_val - (len - neg);
    sp = p->width - len - zeros;
    display_nb(p, str, zeros, sp, neg);
}

void       print_int(t_params *p)
{
    int     n;
    char    *str;
    int     neg;

    n = va_arg(p->va, int);
    str = ft_itoa(n);
    if (n == 0 && p->prec && p->prec_val == 0)
    {
        free(str);
        str = ft_strdup("");
    }
    if (str)
    {
        neg = n < 0 ? 1 : 0;
        pre_display(p, str, neg);
        free(str);
    }
}

void        print_hexa(t_params *p, int maj)
{
    unsigned int    n;
    char            *str;

    n = va_arg(p->va, unsigned int);
    if (maj)
        str = ft_itoa_base((long)n, HEXA_U);
    else
        str = ft_itoa_base((long)n, HEXA_L);
    if (n == 0 && p->prec && p->prec_val == 0)
    {
        free(str);
        str = ft_strdup("");
    }
    if (str)
    {
        pre_display(p, str, 0);
        free(str);
    }
}

void        print_uint(t_params *p)
{
    unsigned int    n;
    char            *str;

    n = va_arg(p->va, unsigned int);
    str = ft_itoa_base((long)n, "0123456789");
    if (n == 0 && p->prec && p->prec_val == 0)
    {
        free(str);
        str = ft_strdup("");
    }
    if (str)
    {
        pre_display(p, str, 0);
        free(str);
    }
}
