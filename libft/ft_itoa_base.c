/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:44:18 by jocaille          #+#    #+#             */
/*   Updated: 2020/07/05 18:11:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_str(long n, int len_b, char *base)
{
	char	*nb;
	long	num;
	int		i;
	int		len;

	len = 1;
	num = n;
	while (n / len_b)
	{
		n /= len_b;
		len++;
	}
	if (!(nb = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb[len] = '\0';
	i = len - 1;
	while (i > 0)
	{
		nb[i--] = base[num % len_b];
		num /= len_b;
	}
	nb[i] = base[num];
	return (nb);
}

char		*ft_itoa_base(long nb, char *base)
{
	int		len_b;
	char	*s;

	len_b = ft_strlen(base);
	if (nb < 0)
		nb = -nb;
	s = ft_create_str(nb, len_b, base);
	if (!s)
		return (NULL);
	return (s);
}
