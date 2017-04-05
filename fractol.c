/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:17:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/03 07:48:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	d_j(t_img *img)
{
	img->z = (t_cmplx){img->plan.x_a, img->plan.y_a};
	img->c = (t_cmplx){img->julia_x, img->julia_y};
	img->j = 0;
	while (img->j < img->nb_i && (img->z.i * img->z.i + img->z.r * img->z.r)
			< 4)
	{
		img->tmp = img->z.r;
		img->z.r = img->z.r * img->z.r - img->z.i * img->z.i + img->c.r;
		img->z.i = 2 * img->tmp * img->z.i + img->c.i;
		++img->j;
	}
	if (img->j == img->nb_i)
//		img->color = mlx_get_color_value(img->mlx_ptr, GREENY);
		get_color(img);
	else
		get_color(img);
	draw_pixel(img, img->x, img->y);
}

void	draw_julia(t_img *img)
{
	const double	save_x = img->plan.x_a;
	const double	save_y = img->plan.y_a;

	img->y = 0;
	while (img->y < HEIGHT)
	{
		img->plan.x_a = save_x;
		img->x = 0;
		while (img->x < WIDTH)
		{
			if (*(unsigned int*)(img->pxl_ptr + ((img->bit_per_pxl *
			(img->x)) + img->size_line * (img->y))) == 0x000000)
				d_j(img);
			++img->x;
			img->plan.x_a += img->plan.step_x;
		}
		++img->y;
		img->plan.y_a += img->plan.step_y;
	}
	img->plan.x_a = save_x;
	img->plan.y_a = save_y;
}

int		main(int argc, char **argv)
{
	t_img	*img;

	if (check_error(argc, argv[1]))
	{
		ft_putendl("Usage : ./fractol [Arg1]");
		ft_putendl("Arg1 being \"Julia\" or \"Mandelbrot\" or \"Ship\"");
		return (1);
	}
	if (!(img = init_image()))
		ft_mlx_error();
	if (argv[1][0] == 'm' || argv[1][0] == 'M')
		img->type = 'm';
	else if (argv[1][0] == 's' || argv[1][0] == 'S')
		img->type = 's';
	else if (argv[1][0] == 'j' || argv[1][0] == 'J')
		img->type = 'j';
	mlx_hook(img->win_ptr, 2, 1L << 8, grab_key, img);
	mlx_expose_hook(img->win_ptr, grab_expose, img);
	mlx_hook(img->win_ptr, MOTION_NOTIFY, POINTER_MOTION, motion_notify, img);
	mlx_mouse_hook(img->win_ptr, mouse_hook, img);
	mlx_loop(img->mlx_ptr);
	return (0);
}
