/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:34:10 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/11 12:34:11 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_button		key_status(int key, t_fdf *ptr)
{
	if (key == 8)
	{
		if (ptr->keyboard->c_button == NOT_PRESSED)
			return (IS_PRESSED);
		else
			return (NOT_PRESSED);
	}
	return (ptr->keyboard->c_button);
}

static int			scale_status(int key, t_fdf *ptr)
{
	if (key == 69)
		return (1);
	if (ptr->scale == 1)
		return (0);
	return (-1);
}

int					key_press(int key, t_fdf *ptr)
{
	if (key == 53)
		exit(1);
	if (key == 69 || key == 78)
		ptr->scale += scale_status(key, ptr);
	if (key == 12 || key == 13)
		ptr->angle->alpha_x += key == 12 ? 0.02 : -0.02;
	if (key == 0 || key == 1)
		ptr->angle->alpha_y += key == 0 ? 0.02 : -0.02;
	if (key == 6 || key == 7)
		ptr->angle->alpha_z += key == 6 ? 0.02 : -0.02;
	if (key == 126 || key == 125)
		ptr->move->vert += key == 126 ? -10 : 10;
	if (key == 123 || key == 124)
		ptr->move->hor += key == 123 ? -10 : 10;
	if (key == 116 || key == 121)
		ptr->height += key == 116 ? 1 : -1;
	if (key == 20 || key == 21)
		ptr->height += key == 20 ? 1 : -1;
	if (key == 34 || key == 35)
		change_projection(key, ptr);
	ptr->keyboard->m_button = key == 46 ? IS_PRESSED : NOT_PRESSED;
	ptr->keyboard->r_button = key == 15 ? IS_PRESSED : NOT_PRESSED;
	ptr->keyboard->c_button = key_status(key, ptr);
	draw(ptr);
	return (0);
}

int					key_release(int key, t_fdf *ptr)
{
	if (key == 46)
		ptr->keyboard->m_button = NOT_PRESSED;
	if (key == 15)
		ptr->keyboard->r_button = NOT_PRESSED;
	return (0);
}
