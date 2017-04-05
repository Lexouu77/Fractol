/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:35:28 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/23 22:34:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*next_lst;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		next_lst = list->next;
		ft_lstdelone(&list, del);
		list = next_lst;
	}
	*alst = NULL;
}
