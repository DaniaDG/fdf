/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:39:28 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/21 12:39:29 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "colors.h"
# include "get_next_line.h"

# define IMG_H		1080
# define IMG_W		1600
# define MENU_H		0
# define MENU_W		0
# define HEIGHT		IMG_H + MENU_H
# define WIDTH		IMG_W + MENU_W

typedef struct		s_stack
{
	int				coord;
	int				color;
	struct s_stack	*next;
}					t_stack;

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef enum
{
	IS_PRESSED,
	NOT_PRESSED
}	t_button;

typedef struct		s_mouse
{
	int			x;
	int			y;
	int			tmp_x;
	int			tmp_y;
	t_button	button;
}					t_mouse;

typedef struct		s_keyboard
{
	t_button	m_button;
	t_button	r_button;
	t_button	c_button;
}					t_keyboard;

typedef struct		s_dots
{
	int		x;
	int		y;
	int		z;
	int		color;
}					t_dots;

typedef struct		s_angle
{
	double	alpha_x;
	double	alpha_y;
	double	alpha_z;
}					t_angle;

typedef struct		s_move
{
	int		vert;
	int		hor;
}					t_move;

typedef struct		s_color
{
	int		start;
	int		end;
}					t_color;

typedef struct		s_fdf
{
	int				i;
	int				j;
	int				min;
	int				max;
	int				middle;
	t_stack			*stack;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				scale;
	int				height;
	t_projection	projection;
	t_angle			*angle;
	t_move			*move;
	t_dots			**dot;
	t_mouse			*mouse;
	t_keyboard		*keyboard;
}					t_fdf;

void				init_fdf(t_fdf *ptr);
t_angle				*init_angles(void);
t_move				*init_move(void);
t_dots				**init_map(t_fdf *ptr);
t_mouse				*init_mouse(void);
t_keyboard			*init_keyboard(void);
int					reading(int fd, t_fdf *ptr);
int					get_color(char *str);
void				draw(t_fdf *ptr);
void				create_map(t_fdf *ptr);
void				rotate(t_dots *dot, t_angle *angle);
int					grad(int current, int min, int max, t_color color);
int					draw_grid(t_fdf *ptr, t_dots **dot);
int					key_press(int key, t_fdf *ptr);
int					key_release(int key, t_fdf *ptr);
int					mouse_press(int key, int x, int y, t_fdf *ptr);
int					mouse_release(int key, int x, int y, t_fdf *ptr);
int					mouse_move(int x, int y, t_fdf *ptr);
int					get_color_grad(t_dots current, t_dots start, t_dots end,
									t_dots delta);
int					iso(int *x, int *y, int z);
void				change_projection(int key, t_fdf *ptr);
int					get_scale(t_fdf *ptr);
int					turn_off(void *param);
void				hooks(t_fdf *ptr);
void				free_arr(void **arr, int i);
void				error(char *str);
void				draw_background(t_fdf *ptr);
int					red(int rgb);
int					green(int rgb);
int					blue(int rgb);
int					rgb(int r, int g, int b);

#endif
