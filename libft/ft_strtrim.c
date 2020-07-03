/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:31:23 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/05 16:31:25 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1) - 1;
	i = 0;
	while (size >= 0 && ft_check(s1[size], set))
		size--;
	while (s1[i] && size >= 0 && ft_check(s1[i], set))
	{
		size--;
		i++;
	}
	size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	j = 0;
	while (j < size)
		str[j++] = s1[i++];
	return (str);
}
