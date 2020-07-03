/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:09:06 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/12 15:09:09 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;
	int		size;
	int		i;

	i = 1;
	start = NULL;
	size = ft_lstsize(lst);
	if (size)
		start = ft_lstnew((*f)(lst->content));
	tmp = start;
	while (i < size)
	{
		lst = lst->next;
		tmp->next = ft_lstnew((*f)(lst->content));
		tmp = tmp->next;
		i++;
	}
	(void)(*del);
	return (start);
}
