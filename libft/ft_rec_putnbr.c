/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 05:39:47 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/11 05:40:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rec_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}
