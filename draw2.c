/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:56:04 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/30 23:18:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*init_image(void)
{
	t_img *tmp_img;

	if ((!(tmp_img = (t_img *)malloc(sizeof(t_img)))) ||
			(!(tmp_img->mlx_ptr = mlx_init())) ||
			(!(tmp_img->win_ptr =
			mlx_new_window(tmp_img->mlx_ptr, WIDTH, HEIGHT, TITLE))))
		return (NULL);
	tmp_img->zoom = 1;
	tmp_img->flou = 0;
	tmp_img->c_value = 0;
	tmp_img->start = 0;
	tmp_img->nb_i = 50;
	tmp_img->reset = 0;
	tmp_img->img_ptr = mlx_new_image(tmp_img->mlx_ptr, WIDTH, HEIGHT);
	tmp_img->pxl_ptr = mlx_get_data_addr(tmp_img->img_ptr,
			&(tmp_img->bit_per_pxl), &(tmp_img->size_line),
			&(tmp_img->endian));
	tmp_img->bpp = tmp_img->bit_per_pxl / 8;
	return (tmp_img);
}

int		motion_notify(int x, int y, t_img *img)
{
	clear_map(img);
	img->julia_x = img->plan.x_a + ((double)x * img->plan.step_x);
	img->julia_y = img->plan.y_a + ((double)y * img->plan.step_y);
	draw_map(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	return (1);
}

void	mouse_hook2(t_img *img)
{
	clear_map(img);
	img->plan.x_a -= img->plan.step_x * (WIDTH / 2);
	img->plan.y_a -= img->plan.step_y * (HEIGHT / 2);
	img->plan.x_b += img->plan.step_x * (WIDTH / 2);
	img->plan.y_b += img->plan.step_y * (HEIGHT / 2);
	img->plan.step_x = (img->plan.x_b - img->plan.x_a) / WIDTH;
	img->plan.step_y = (img->plan.y_b - img->plan.y_a) / HEIGHT;
	draw_map(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}

int		mouse_hook(int button, int x, int y, t_img *img)
{
	if (button == 5 || button == 1)
	{
		clear_map(img);
		move_map(img, x - WIDTH / 2, y - HEIGHT / 2);
		img->plan.x_a += img->plan.step_x * (WIDTH / 4);
		img->plan.y_a += img->plan.step_y * (HEIGHT / 4);
		img->plan.x_b -= img->plan.step_x * (WIDTH / 4);
		img->plan.y_b -= img->plan.step_y * (HEIGHT / 4);
		img->plan.step_x = (img->plan.x_b - img->plan.x_a) / WIDTH;
		img->plan.step_y = (img->plan.y_b - img->plan.y_a) / HEIGHT;
		move_map(img, (x - WIDTH / 2) * -1, (y - HEIGHT / 2) * -1);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (button == 4 || button == 2)
		mouse_hook2(img);
	return (1);
}
