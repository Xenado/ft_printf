/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:41:21 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/04 17:04:00 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(int n)
{
	int		len_n;

	len_n = 1;
	if (n < 0)
		len_n++;
	while (n / 10)
	{
		n /= 10;
		len_n++;
	}
	return (len_n);
}

char		*ft_itoa(int n)
{
	char		*nbr;
	int			len_n;
	int			i;
	long int	nb;

	len_n = ft_len_n(n);
	i = 0;
	nb = n;
	nbr = malloc(sizeof(char) * (len_n + 1));
	if (!nbr)
		return (NULL);
	nbr[len_n--] = '\0';
	if (n < 0)
	{
		nbr[i++] = '-';
		nb = -nb;
	}
	while (len_n >= i)
	{
		nbr[len_n] = nb % 10 + '0';
		nb /= 10;
		len_n--;
	}
	return (nbr);
}
