/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_scale(t_fdf *ptr)
{
	int		scale;
	int		w;
	int		h;
	int		z;

	z = abs(ptr->max - ptr->min);
	w = (IMG_W / (ptr->j > z ? ptr->j : z)) / 2;
	h = (IMG_H / (ptr->i > z ? ptr->i : z)) / 2;
	scale = w < h ? w : h;
	return (!scale ? 1 : scale);
}

int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

void	error(char *str)
{
	if (!errno)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}

void	free_arr(void **arr, int i)
{
	while (i--)
		ft_memdel((void **)&arr[i]);
	ft_memdel(arr);
	free(arr);
}

void	hooks(t_fdf *ptr)
{
	mlx_hook(ptr->win, 2, 0, key_press, ptr);
	mlx_hook(ptr->win, 3, 0, key_release, ptr);
	mlx_hook(ptr->win, 4, 0, mouse_press, ptr);
	mlx_hook(ptr->win, 5, 0, mouse_release, ptr);
	mlx_hook(ptr->win, 6, 0, mouse_move, ptr);
	mlx_hook(ptr->win, 17, 0, turn_off, ptr);
	mlx_loop(ptr->mlx);
}
