/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:11:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/20 08:58:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1 - (unsigned char)*s2));
		++s1;
		++s2;
	}
	return ((*s1 - *s2));
}
