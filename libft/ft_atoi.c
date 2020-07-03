/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:19:35 by jocaille          #+#    #+#             */
/*   Updated: 2020/04/23 15:18:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		neg;
	int		i;
	int		len;

	i = 0;
	nb = 0;
	neg = 1;
	len = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i++] - '0';
		len++;
	}
	if (len > 18)
		return (neg == 1 ? -1 : 0);
	return (nb * neg);
}
