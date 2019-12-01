/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:31:36 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/15 09:31:37 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	scale_status(int key, t_fdf *ptr)
{
	if (key == 5)
		return (1);
	if (ptr->scale == 1)
		return (0);
	return (-1);
}

int			mouse_press(int key, int x, int y, t_fdf *ptr)
{
	(void)x;
	(void)y;
	if (key == 5 || key == 4)
		ptr->scale += scale_status(key, ptr);
	draw(ptr);
	if (key == 1)
		ptr->mouse->button = IS_PRESSED;
	return (0);
}

int			mouse_release(int key, int x, int y, t_fdf *ptr)
{
	(void)x;
	(void)y;
	if (key == 1)
		ptr->mouse->button = NOT_PRESSED;
	return (0);
}

int			mouse_move(int x, int y, t_fdf *ptr)
{
	ptr->mouse->tmp_x = ptr->mouse->x;
	ptr->mouse->tmp_y = ptr->mouse->y;
	ptr->mouse->x = x;
	ptr->mouse->y = y;
	if (ptr->mouse->button == IS_PRESSED &&
		ptr->keyboard->m_button == IS_PRESSED)
	{
		ptr->move->hor += (x - ptr->mouse->tmp_x);
		ptr->move->vert += (y - ptr->mouse->tmp_y);
	}
	if (ptr->mouse->button == IS_PRESSED &&
		ptr->keyboard->r_button == IS_PRESSED)
	{
		ptr->angle->alpha_z += (x - ptr->mouse->tmp_x) * 0.002;
		ptr->angle->alpha_x += (y - ptr->mouse->tmp_y) * 0.002;
	}
	draw(ptr);
	return (0);
}
