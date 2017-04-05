/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:08:45 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/30 00:47:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb == 0)
		return (0);
	i = nb;
	while ((unsigned int)nb < (i * i))
		i--;
	if ((unsigned int)nb == (i * i))
		return (i);
	return (0);
}
