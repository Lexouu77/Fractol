/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:36:14 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/23 22:40:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **alst, t_list *new)
{
	t_list*tmp;

	if (!new)
		return (NULL);
	if (!alst || !*alst)
		return (new);
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
