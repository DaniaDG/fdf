/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_fdf *ptr)
{
	if (!(ptr->mlx = mlx_init()))
		error("mlx init error");
	if (!(ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "FDF")))
		error("windows init error");
	if (!(ptr->img = mlx_new_image(ptr->mlx, IMG_W, IMG_H)))
		error("image init error");
	ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bits_per_pixel),
										&(ptr->size_line), &(ptr->endian));
}

void		init_fdf(t_fdf *ptr)
{
	init_mlx(ptr);
	ptr->scale = get_scale(ptr);
	ptr->height = 0;
	ptr->projection = ISO;
	if (!(ptr->angle = init_angles()))
		error("init error");
	if (!(ptr->move = init_move()))
		error("init error");
	if (!(ptr->dot = init_map(ptr)))
		error("map init error");
	if (!(ptr->mouse = init_mouse()))
		error("init error");
	if (!(ptr->keyboard = init_keyboard()))
		error("init error");
}
