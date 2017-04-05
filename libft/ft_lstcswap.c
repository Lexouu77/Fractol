/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 22:41:05 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/30 00:57:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcswap(t_list *lst1, t_list *lst2)
{
	void	*tmpcontent;
	size_t	tmpsize;

	tmpcontent = lst1->content;
	tmpsize = lst1->content_size;
	lst1->content = lst2->content;
	lst1->content_size = lst2->content_size;
	lst2->content = tmpcontent;
	lst2->content_size = tmpsize;
}
