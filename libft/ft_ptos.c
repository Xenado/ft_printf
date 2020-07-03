/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:55:41 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/01 15:55:41 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_size_add(unsigned long n)
{
    int len;

    len = 1;
    while (n / 16)
    {
        n /= 16;
        len++;
    }
    return (len);
}

char    *ft_ptos(void *p, int prefix)
{
    const char      *base = "0123456789abcdef";
    unsigned long   n;
    int             len;
    char            *str;

    if (p == NULL)
        return (NULL);
    n = (unsigned long)p;
    len = ft_size_add(n);
    if (prefix)
        len += 2;
    if (!(str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    str[len] = '\0';
    if (prefix)
        str = ft_memcpy((void * )str, "0x", 2);
    str[--len] = base[n % 16];
    n /= 16;
    while (n > 0)
    {
        str[--len] = base[n % 16];
        n /= 16;
    }
    return (str);
}