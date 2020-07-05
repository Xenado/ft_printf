/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:47:34 by jocaille          #+#    #+#             */
/*   Updated: 2020/07/05 18:19:42 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	display_nb(t_params *p, char *str, t_padd *padd, int neg)
{
	p->len = padd->zeros > 0 ? p->len + padd->zeros : p->len;
	p->len = padd->sp > 0 ? p->len + padd->sp : p->len;
	p->len += ft_strlen(str);
	if (p->zero || p->minus)
	{
		if (neg)
		{
			ft_putchar_fd(*str++, 1);
		}
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
		if (neg)
			ft_putchar_fd(*str++, 1);
		while (padd->zeros-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
	}
}

static void	pre_display(t_params *p, char *str, t_padd *padd, int neg)
{
	int	len;

	len = ft_strlen(str);
	padd->zeros = 0;
	if (p->zero && p->width > len)
		padd->zeros = p->width - len;
	if (p->prec && p->prec_val > len - neg)
		padd->zeros = p->prec_val - (len - neg);
	padd->sp = p->width - len - padd->zeros;
	display_nb(p, str, padd, neg);
}

void		print_int(t_params *p, t_padd *padd)
{
	int		n;
	char	*str;
	int		neg;

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
		pre_display(p, str, padd, neg);
		free(str);
	}
}

void		print_hexa(t_params *p, t_padd *padd, int maj)
{
	unsigned int	n;
	char			*str;

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
		pre_display(p, str, padd, 0);
		free(str);
	}
}

void		print_uint(t_params *p, t_padd *padd)
{
	unsigned int	n;
	char			*str;

	n = va_arg(p->va, unsigned int);
	str = ft_itoa_base((long)n, "0123456789");
	if (n == 0 && p->prec && p->prec_val == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (str)
	{
		pre_display(p, str, padd, 0);
		free(str);
	}
}
