/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jocaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:14:41 by user42            #+#    #+#             */
/*   Updated: 2020/07/03 18:07:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_c(t_params *p)
{
	int		sp;
	char	c;

	c = va_arg(p->va, int);
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

static void	display_s(t_params *p, char *str, int len, int sp)
{
	int	i;

	i = 0;
	if (p->minus)
		while (i < len)
			ft_putchar_fd(str[i++], 1);
	if (sp > 0)
		p->len += sp;
	while (sp-- > 0)
		ft_putchar_fd(' ', 1);
	if (!p->minus)
		while (i < len)
			ft_putchar_fd(str[i++], 1);
	p->len += len;
}

void		print_s(t_params *p)
{
	char	*str;
	int		sp;
	int		len;
	int		need_free;

	need_free = 0;
	str = va_arg(p->va, char *);
	if (str == NULL)
	{
		if (p->prec && p->prec_val < 7)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
		need_free = 1;
	}
	len = ft_strlen(str);
	if (p->prec)
		len = ft_min(len, p->prec_val);
	sp = p->width - len;
	display_s(p, str, len, sp);
	if (need_free)
		free(str);
}

static void	display_p(t_params *p, char *str, int zeros, int sp, int flag)
{
	if (zeros > 0)
		p->len += zeros;
	if (sp > 0)
		p->len += sp;
	p->len += ft_strlen(str) + 2 - flag;
	if (p->zero || p->minus)
	{
		if (!flag)
			ft_putstr_fd("0x", 1);
		while (zeros-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
		while (sp-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (sp-- > 0)
			ft_putchar_fd(' ', 1);
		if (!flag)
			ft_putstr_fd("0x", 1);
		while (zeros-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
	}
}

void		print_p(t_params *p)
{
	void	*ptr;
	char	*str;
	int		len;
	int		flag;	
	int		sp;
	int		zeros;

	ptr = va_arg(p->va, void *);
	str = ft_ptos(ptr, 0);
	flag = str == NULL ? 2 : 0;
	if (str == NULL)
		str = ft_strdup("(nil)");
	len = ft_strlen(str);
	zeros = 0;
	if (p->zero && p->width > len + 2 - flag)
		zeros = p->width - (len + 2 - flag);
	if (p->prec && p->prec_val > len)
		zeros = p->prec_val - len;
	sp = p->width - (len + 2 - flag) - zeros;
	display_p(p, str, zeros, sp, flag);
	free(str);
}
