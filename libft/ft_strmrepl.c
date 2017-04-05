/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmrepl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 22:14:19 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/29 22:16:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strmrepl(char *src, char *to_find, char c)
{
	while (*to_find)
	{
		ft_strrepl(src, *to_find, c);
		to_find++;
	}
}
