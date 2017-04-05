/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:21:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/03 08:36:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		grab_key2(int keycode, t_img *img)
{
	if (keycode == 53)
	{
		free(img);
		exit(0);
	}
	if (keycode == 8)
	{
		if (img->type == 's')
			img->type = 'm';
		else if (img->type == 'm')
			img->type = 'j';
		else if (img->type == 'j')
			img->type = 's';
		set_plan(img);
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 36)
	{
		img->start = 1;
		clear_map(img);
		grab_expose(img);
	}
	return (0);
}

int		grab_key3(int keycode, t_img *img)
{
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			move_map(img, (double)WIDTH * 0.05, 0);
		else
			move_map(img, (double)WIDTH * -0.05, 0);
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 126)
			move_map(img, 0, (double)HEIGHT * 0.05);
		else
			move_map(img, 0, (double)HEIGHT * -0.05);
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	return (0);
}

int		grab_key4(int keycode, t_img *img)
{
	if (keycode == 78)
	{
		img->plan.x_a -= img->plan.step_x * WIDTH / 2;
		img->plan.y_a -= img->plan.step_y * HEIGHT / 2;
		img->plan.x_b += img->plan.step_x * WIDTH / 2;
		img->plan.y_b += img->plan.step_y * HEIGHT / 2;
		img->plan.step_x = (img->plan.x_b - img->plan.x_a) / WIDTH;
		img->plan.step_y = (img->plan.y_b - img->plan.y_a) / HEIGHT;
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 9)
	{
		if (img->c_value == 0)
			img->c_value = 1;
		else if (img->c_value == 1)
			img->c_value = 0;
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	return (0);
}

int		grab_key5(int keycode, t_img *img)
{
	if (keycode == 15)
	{
		set_plan(img);
		img->zoom = 1;
		img->flou = 0;
		img->nb_i = 50;
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 69)
	{
		img->plan.x_a += img->plan.step_x * WIDTH / 4;
		img->plan.y_a += img->plan.step_y * HEIGHT / 4;
		img->plan.x_b -= img->plan.step_x * WIDTH / 4;
		img->plan.y_b -= img->plan.step_y * HEIGHT / 4;
		img->plan.step_x = (img->plan.x_b - img->plan.x_a) / WIDTH;
		img->plan.step_y = (img->plan.y_b - img->plan.y_a) / HEIGHT;
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 3)
		img->flou = (img->flou) ? 0 : 1;
	return (0);
}

int		grab_key(int keycode, t_img *img)
{
	if (keycode == 34)
	{
		img->nb_i += 50;
		if (img->nb_i > 1000)
			img->nb_i = 10;
		clear_map(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 46)
	{
		img->reset = 0;
		clear_map(img);
		grab_expose(img);
	}
	grab_key2(keycode, img);
	grab_key3(keycode, img);
	grab_key4(keycode, img);
	grab_key5(keycode, img);
	return (0);
}
