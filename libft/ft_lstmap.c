/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:36:04 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/23 21:36:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list*start;
	t_list*new;
	t_list*tmp;

	if (!lst)
		return (NULL);
	tmp = NULL;
	start = NULL;
	while (lst)
	{
		new = f(ft_lstnew(lst->content, lst->content_size));
		if (!start)
			start = new;
		tmp = ft_lstpush(&tmp, new);
		lst = lst->next;
	}
	return (start);
}
