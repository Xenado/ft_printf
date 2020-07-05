/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:30:59 by jocaille          #+#    #+#             */
/*   Updated: 2020/07/05 18:36:01 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_type(t_params *p, t_padd *padd)
{
	if (p->type == 'c')
		print_c(p, padd);
	else if (p->type == 's')
		print_s(p, padd);
	else if (p->type == 'p')
		print_p(p, padd);
	else if (p->type == 'd' || p->type == 'i')
		print_int(p, padd);
	else if (p->type == 'u')
		print_uint(p, padd);
	else if (p->type == 'x')
		print_hexa(p, padd, 0);
	else if (p->type == 'X')
		print_hexa(p, padd, 1);
	else if (p->type == '%')
	{
		write(1, "%", 1);
		p->len++;
	}
}

static void	print_param(t_params *p, t_padd *padd)
{
	p->str++;
	init_params(p, padd);
	parse_flags(p);
	parse_width(p);
	parse_prec(p);
	parse_type(p);
	if (p->type != 0)
		print_type(p, padd);
}

int			ft_printf(const char *format, ...)
{
	t_params	*p;
	t_padd		*padd;
	int		len;

	if (!(p = malloc(sizeof(t_params))))
		return (0);
	if (!(padd = malloc(sizeof(t_padd))))
		return (0);
	p->str = (char *)format;
	va_start(p->va, format);
	p->len = 0;
	while (*(p->str))
		if (*(p->str) != '%')
		{
			write(1, p->str, 1);
			p->str++;
			p->len++;
		}
		else
			print_param(p, padd);
	va_end(p->va);
	free(padd);
	len = p->len;
	free(p);
	return (len);
}
