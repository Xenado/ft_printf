/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:30:59 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/30 21:05:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_mod(t_params *p)
{
	int		sp;
	char	c;

	c = '%';
	sp = p->width - 1;
	if (p->minus)
		ft_putchar_fd(c, 1);
	if (sp > 0)
		p->len += sp;
	while (sp-- > 0)
		ft_putchar_fd(' ', 1);
	if (!p->minus)
		ft_putchar_fd(c, 1);
	p->len++;
}

static void	print_type(t_params *p)
{
	if (p->type == 'c')
		print_c(p);
	else if (p->type == 's')
		print_s(p);
	else if (p->type == 'p')
		print_p(p);
	else if (p->type == 'd' || p->type == 'i')
		print_int(p);
	else if (p->type == 'u')
		print_uint(p);
	else if (p->type == 'x')
		print_hexa(p, 0);
	else if (p->type == 'X')
		print_hexa(p, 1);
	else if (p->type == '%')
		print_mod(p);
}

static void	print_param(t_params *p)
{
	p->str++;
	init_params(p);
	parse_flags(p);
	parse_width(p);
	parse_prec(p);
	parse_type(p);
	if (p->type != 0)
		print_type(p);
}

int			ft_printf(const char *format, ...)
{
	t_params	*p;

	if (!(p = malloc(sizeof(t_params))))
		return (0);
	p->str = (char *)format;
	va_start(p->va, format);
	p->len = 0;
	while (*(p->str))
	{
		if (*(p->str) != '%')
		{
			write(1, p->str, 1);
			p->str++;
			p->len++;
		}
		else
			print_param(p);
	}
	va_end(p->va);
	return (p->len);
}
