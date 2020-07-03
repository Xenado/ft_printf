/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:38:56 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/05 16:39:05 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char const *s, char c)
{
	int		nb_w;
	int		i;
	int		j;

	i = 0;
	nb_w = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
			nb_w++;
		i += j;
	}
	return (nb_w);
}

static char	*ft_createw(char const *s, char c)
{
	int		len_w;
	int		i;
	char	*word;

	i = 0;
	len_w = 0;
	while (s[len_w] && s[len_w] != c)
		len_w++;
	word = malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (i < len_w)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		nb_w;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	nb_w = ft_countw(s, c);
	words = malloc(sizeof(char *) * (nb_w + 1));
	if (!words)
		return (NULL);
	while (j < nb_w)
	{
		while (s[i] == c)
			i++;
		words[j] = ft_createw(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	words[j] = NULL;
	return (words);
}
