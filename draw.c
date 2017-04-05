/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:10:15 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/24 12:59:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_img *img, int x, int y)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		*(unsigned int*)(img->pxl_ptr + ((int)(img->bpp *
			(x)) + img->size_line * (y))) = img->color;
}

void	clear_map(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	if (!img->flou)
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->pxl_ptr = mlx_get_data_addr(img->img_ptr,
			&(img->bit_per_pxl), &(img->size_line),
			&(img->endian));
	img->bpp = img->bit_per_pxl / 8;
}

void	print_menu(t_img *img)
{
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2,
			WHITE, "C : Change Fractol");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 20,
			WHITE, "V : Change Color Set");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 40,
			WHITE, "R : Reset");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 60,
			WHITE, "I : Increase Iteration");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 80,
			WHITE, "F : Blur");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 100,
			WHITE, "Arrows : Move");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 140,
			WHITE, "Enter : Start!");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 120,
			WHITE, "M : Show Menu");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 160,
			WHITE, "Esc : Leave");
	mlx_string_put(img->mlx_ptr, img->win_ptr, HEIGHT / 2, WIDTH / 2 - 180,
			WHITE, "-/+ : Zoom/Dezoom");
}

void	draw_map(t_img *img)
{
	if (img->type == 's')
		draw_ship(img);
	if (img->type == 'm')
		draw_mandelbrot(img);
	if (img->type == 'j')
		draw_julia(img);
}

void	move_map(t_img *img, int mx, int my)
{
	img->plan.x_a += img->plan.step_x * mx;
	img->plan.x_b += img->plan.step_x * mx;
	img->plan.y_a += img->plan.step_y * my;
	img->plan.y_b += img->plan.step_y * my;
}
