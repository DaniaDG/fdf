/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redrawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:41:56 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/09 15:41:57 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale_coords(t_fdf *ptr, t_dots *dot)
{
	dot->x *= ptr->scale;
	dot->y *= ptr->scale;
	dot->z *= ptr->scale;
}

static void	move_coords(t_fdf *ptr, t_dots *dot)
{
	dot->x += IMG_W / 2;
	dot->y += IMG_H / 2;
	dot->x += ptr->move->hor;
	dot->y += ptr->move->vert;
}

void		draw(t_fdf *ptr)
{
	int		i;
	int		j;

	draw_background(ptr);
	create_map(ptr);
	i = -1;
	while (++i < ptr->i)
	{
		j = -1;
		while (++j < ptr->j)
		{
			ptr->dot[i][j].x -= ptr->j / 2;
			ptr->dot[i][j].y -= ptr->i / 2;
			ptr->dot[i][j].z += (ptr->dot[i][j].z ? ptr->height : 0);
			scale_coords(ptr, &ptr->dot[i][j]);
			rotate(&ptr->dot[i][j], ptr->angle);
			if (ptr->projection == ISO)
				iso(&ptr->dot[i][j].x, &ptr->dot[i][j].y, ptr->dot[i][j].z);
			move_coords(ptr, &ptr->dot[i][j]);
		}
	}
	draw_grid(ptr, ptr->dot);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
