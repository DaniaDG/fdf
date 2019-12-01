/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:41:56 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/09 15:41:57 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(t_fdf *ptr, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
	{
		i = (x * ptr->bits_per_pixel / 8) + (y * ptr->size_line);
		ptr->data_addr[i] = blue(color);
		ptr->data_addr[++i] = green(color);
		ptr->data_addr[++i] = red(color);
	}
}

void			draw_background(t_fdf *ptr)
{
	int		i;

	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	i = IMG_H * IMG_W * 4;
	while (i--)
	{
		ptr->data_addr[--i] = red(BACKGROUND);
		ptr->data_addr[--i] = green(BACKGROUND);
		ptr->data_addr[--i] = blue(BACKGROUND);
	}
}

static void		draw_line_values(t_dots *d, t_dots *s, t_dots dot1, t_dots dot2)
{
	d->x = abs(dot2.x - dot1.x);
	d->y = abs(dot2.y - dot1.y);
	s->x = dot1.x < dot2.x ? 1 : -1;
	s->y = dot1.y < dot2.y ? 1 : -1;
}

static void		draw_line(t_fdf *ptr, t_dots dot1, t_dots dot2)
{
	t_dots	delta;
	t_dots	sign;
	t_dots	current;
	int		error[2];

	current = dot1;
	draw_line_values(&delta, &sign, dot1, dot2);
	error[0] = delta.x - delta.y;
	while (current.x != dot2.x || current.y != dot2.y)
	{
		put_pixel(ptr, current.x, current.y,
					get_color_grad(current, dot1, dot2, delta));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			current.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}

int				draw_grid(t_fdf *ptr, t_dots **dot)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->i)
	{
		j = 0;
		while (j < ptr->j)
		{
			if (j + 1 != ptr->j)
				draw_line(ptr, dot[i][j], dot[i][j + 1]);
			if (i + 1 != ptr->i)
				draw_line(ptr, dot[i][j], dot[i + 1][j]);
			j++;
		}
		i++;
	}
	return (0);
}
