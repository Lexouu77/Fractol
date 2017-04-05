/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 22:10:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/14 04:49:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	d_m(t_img *img)
{
	img->c = (t_cmplx){img->plan.x_a, img->plan.y_a};
	img->z = (t_cmplx){0, 0};
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
		img->color = mlx_get_color_value(img->mlx_ptr, BLACK);
	else
		get_color(img);
	draw_pixel(img, img->x, img->y);
}

void	draw_mandelbrot(t_img *img)
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
			d_m(img);
			++img->x;
			img->plan.x_a += img->plan.step_x;
		}
		++img->y;
		img->plan.y_a += img->plan.step_y;
	}
	img->plan.x_a = save_x;
	img->plan.y_a = save_y;
}

void	d_s(t_img *img)
{
	img->c = (t_cmplx){img->plan.x_a, img->plan.y_a};
	img->z = (t_cmplx){0, 0};
	img->j = 0;
	while (img->j < img->nb_i && (img->z.i * img->z.i + img->z.r * img->z.r)
			< 4)
	{
		img->z.r = fabs(img->z.r);
		img->z.i = fabs(img->z.i);
		img->tmp = img->z.r;
		img->z.r = img->z.r * img->z.r - img->z.i * img->z.i - img->c.r;
		img->z.i = 2 * img->tmp * img->z.i + img->c.i;
		++img->j;
	}
	if (img->j == img->nb_i)
		img->color = mlx_get_color_value(img->mlx_ptr, BLACK);
	else
		get_color(img);
	draw_pixel(img, img->x, img->y);
}

void	draw_ship(t_img *img)
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
			d_s(img);
			++img->x;
			img->plan.x_a += img->plan.step_x;
		}
		++img->y;
		img->plan.y_a += img->plan.step_y;
	}
	img->plan.x_a = save_x;
	img->plan.y_a = save_y;
}
