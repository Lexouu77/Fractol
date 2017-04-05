/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:17:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/14 07:58:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "libmx2/mlx.h"
# include <stdio.h>
# include "math.h"
# define TITLE "ahamouda's 42-FRACTOL"
# define WIDTH 1200
# define HEIGHT 800
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define PURPLE 0x800080
# define CYAN 0x00ffff
# define GREENY 0xadff2f
# define POINTER_MOTION (1L<<6)
# define MOTION_NOTIFY 6

typedef struct		s_plan
{
	double			x_a;
	double			y_a;
	double			x_b;
	double			y_b;
	double			step_x;
	double			step_y;
}					t_plan;

typedef struct		s_cmplx
{
	double			r;
	double			i;
}					t_cmplx;

typedef struct		s_img
{
	char			type;
	int				j;
	int				x;
	int				y;
	int				start;
	int				reset;
	double			julia_x;
	double			julia_y;
	int				nb_i;
	double			tmp;
	t_cmplx			z;
	t_cmplx			c;
	t_plan			plan;
	double			zoom;
	int				menu;
	int				flou;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*pxl_ptr;
	int				bit_per_pxl;
	double			bpp;
	int				size_line;
	int				endian;
	int				c_value;
	unsigned int	color;
}					t_img;

void				draw_pixel(t_img *img, int x, int y);
void				clear_map(t_img *img);
void				print_menu(t_img *img);
int					check_error(int c, char *file);
void				ft_mlx_error(void);
void				get_color(t_img *img);
void				draw_ship(t_img *img);
void				draw_julia(t_img *img);
void				draw_mandelbrot(t_img *img);
void				set_plan(t_img *img);
void				draw_map(t_img *img);
int					grab_expose(t_img *img);
void				move_map(t_img *img, int mx, int my);
int					grab_key(int keycode, t_img *img);
int					grab_key2(int keycode, t_img *img);
int					grab_key3(int keycode, t_img *img);
int					grab_key4(int keycode, t_img *img);
int					grab_key5(int keycode, t_img *img);
t_img				*init_image(void);
int					mouse_hook(int button, int x, int y, t_img *img);
void				mouse_hook2(t_img *img);
int					motion_notify(int x, int y, t_img *img);
void				d_m(t_img *img);
void				d_s(t_img *img);
void				d_j(t_img *img);
#endif
