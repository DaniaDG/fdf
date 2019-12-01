/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_angle		*init_angles(void)
{
	t_angle	*angle;

	if (!(angle = (t_angle *)malloc(sizeof(t_angle))))
		return (NULL);
	angle->alpha_x = 0;
	angle->alpha_y = 0;
	angle->alpha_z = 0;
	return (angle);
}

t_move		*init_move(void)
{
	t_move	*move;

	if (!(move = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	move->vert = 0;
	move->hor = 0;
	return (move);
}

t_dots		**init_map(t_fdf *ptr)
{
	int		i;
	t_dots	**dot;

	if (!(dot = (t_dots **)malloc(sizeof(t_dots *) * ptr->i)))
		return (NULL);
	i = 0;
	while (i < ptr->i)
	{
		if (!(dot[i] = (t_dots *)malloc(sizeof(t_dots) * ptr->j)))
		{
			free_arr((void **)dot, i - 1);
			return (NULL);
		}
		i++;
	}
	return (dot);
}

t_mouse		*init_mouse(void)
{
	t_mouse		*mouse;

	if (!(mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		return (NULL);
	mouse->button = NOT_PRESSED;
	return (mouse);
}

t_keyboard	*init_keyboard(void)
{
	t_keyboard		*keyboard;

	if (!(keyboard = (t_keyboard *)malloc(sizeof(t_keyboard))))
		return (NULL);
	keyboard->m_button = NOT_PRESSED;
	keyboard->r_button = NOT_PRESSED;
	keyboard->c_button = NOT_PRESSED;
	return (keyboard);
}
