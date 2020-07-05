/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jocaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:41:54 by user42            #+#    #+#             */
/*   Updated: 2020/07/05 18:39:10 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_c(t_params *p, t_padd *padd)
{
	char	c;

	c = va_arg(p->va, int);
	padd->sp = p->width - 1;
	if (p->minus)
		ft_putchar_fd(c, 1);
	if (padd->sp > 0)
		p->len += padd->sp;
	while (padd->sp-- > 0)
		ft_putchar_fd(' ', 1);
	if (!p->minus)
		ft_putchar_fd(c, 1);
	p->len++;
}

static void	display_s(t_params *p, char *str, int len, t_padd *padd)
{
	int	i;

	i = 0;
	if (p->minus)
		while (i < len)
			ft_putchar_fd(str[i++], 1);
	if (padd->sp > 0)
		p->len += padd->sp;
	while (padd->sp-- > 0)
		ft_putchar_fd(' ', 1);
	if (!p->minus)
		while (i < len)
			ft_putchar_fd(str[i++], 1);
	p->len += len;
}

void		print_s(t_params *p, t_padd *padd)
{
	char	*str;
	int		len;
	int		need_free;

	need_free = 0;
	str = va_arg(p->va, char *);
	if (str == NULL)
	{
		if (p->prec && p->prec_val < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
		need_free = 1;
	}
	len = ft_strlen(str);
	if (p->prec)
		len = ft_min(len, p->prec_val);
	padd->sp = p->width - len;
	display_s(p, str, len, padd);
	if (need_free)
		free(str);
}

static void	display_p(t_params *p, char *str, t_padd *padd, int flag)
{
	if (padd->zeros > 0)
		p->len += padd->zeros;
	if (padd->sp > 0)
		p->len += padd->sp;
	p->len += ft_strlen(str) + 2 - flag;
	if (p->zero || p->minus)
	{
		if (!flag)
			ft_putstr_fd("0x", 1);
		while (padd->zeros-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
		while (padd->sp-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (padd->sp-- > 0)
			ft_putchar_fd(' ', 1);
		if (!flag)
			ft_putstr_fd("0x", 1);
		while (padd->zeros-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
	}
}

void		print_p(t_params *p, t_padd *padd)
{
	void	*ptr;
	char	*str;
	int		len;
	int		flag;

	ptr = va_arg(p->va, void *);
	str = ft_ptos(ptr, 0);
	flag = str == NULL ? 2 : 0;
	if (str == NULL)
		str = ft_strdup("(nil)");
	len = ft_strlen(str);
	padd->zeros = 0;
	if (p->zero && p->width > len + 2 - flag)
		padd->zeros = p->width - (len + 2 - flag);
	if (p->prec && p->prec_val > len)
		padd->zeros = p->prec_val - len;
	padd->sp = p->width - (len + 2 - flag) - padd->zeros;
	display_p(p, str, padd, flag);
	free(str);
}
