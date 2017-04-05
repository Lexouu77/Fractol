/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:11:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/30 23:19:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_error(int c, char *file)
{
	if (c != 2)
		return (1);
	if ((ft_strcmp(file, "Julia") && ft_strcmp(file, "julia")) &&
			((ft_strcmp(file, "Mandelbrot") && ft_strcmp(file, "mandelbrot")))
			&& ((ft_strcmp(file, "Ship") && ft_strcmp(file, "ship"))))
		return (1);
	return (0);
}

int		grab_expose(t_img *img)
{
	static int	x = 0;

	if (!img->reset && x)
	{
		x = 0;
		img->start = 0;
		print_menu(img);
	}
	if (!img->start && !x)
	{
		print_menu(img);
		x++;
		img->reset++;
		img->start++;
	}
	else
	{
		set_plan(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	return (0);
}

void	set_plan(t_img *img)
{
	if (img->type == 'j')
		img->plan = (t_plan){1.5, -1, -1.5, 1, (-3 / img->zoom) / WIDTH,
			(2 / img->zoom) / HEIGHT};
	if (img->type == 'm')
		img->plan = (t_plan){-2, 1, 1, -1, (3 / img->zoom) / WIDTH,
			(-2 / img->zoom) / HEIGHT};
	if (img->type == 's')
		img->plan = (t_plan){4, -2, -2, 2, (-6 / img->zoom) / WIDTH,
			(4 / img->zoom) / HEIGHT};
}

void	ft_mlx_error(void)
{
	ft_putendl("Mlx-lib Error.");
	exit(-1);
}

void	get_color(t_img *img)
{
	unsigned int		c;
	const unsigned char	b = (sin(0.016 * img->j + 4) * 230 + 25);
	const unsigned char	g = (sin(0.013 * img->j + 2) * 230 + 25);
	const unsigned char	r = (sin(0.01 * img->j + 1) * 230 + 25);

	//c = (img->type == 'j') ? (img->j * (img->j + img->j) % 256) : 0;
//	c = (img->type == 'j') ? (128 << 24 | c << 8 | c << 2) : 0;
	c = 0x00000000 | r << 16 | g << 8 | b ;
/*	if (img->type == 'm')
	{
		if (img->c_value == 0)
		{
			c = sin(img->j * (img->j + img->j) % 256) * 256;
			if (img->j < 5)
				c = 175 << 24 | c << 16 | c << 2;
			else
				c = c << 16 | c << 2;
		}
		c = (img->c_value == 1) ? img->j * (img->j + img->j) % 256 : c;
		c = (img->c_value == 1) ? c << 16 | c << 2 : c;
	}
	else if (img->type == 's')
	{
		c = img->j * (img->j + img->j) % 256;
		c = (img->j < 7) ? (128 << 24 | c << 8 | c << 3) : (c << 8 | c << 3);
	}*/
	if (img->type == 's')
		c = 0x00000000 | r | g << 8 | b << 16;
	img->color = mlx_get_color_value(img->mlx_ptr, c);
}
