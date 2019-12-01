/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:40:15 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/15 08:40:16 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x_rotation(int *y, int *z, double alpha)
{
	int		tmp;

	tmp = *y;
	*y = tmp * cos(alpha) + (*z) * sin(alpha);
	*z = -tmp * sin(alpha) + (*z) * cos(alpha);
	return (0);
}

int		y_rotation(int *x, int *z, double alpha)
{
	int		tmp;

	tmp = *x;
	*x = tmp * cos(alpha) + (*z) * sin(alpha);
	*z = -tmp * sin(alpha) + (*z) * cos(alpha);
	return (0);
}

int		z_rotation(int *x, int *y, double alpha)
{
	int		tmp;

	tmp = *x;
	*x = tmp * cos(alpha) - (*y) * sin(alpha);
	*y = tmp * sin(alpha) + (*y) * cos(alpha);
	return (0);
}

void	rotate(t_dots *dot, t_angle *angle)
{
	x_rotation(&dot->y, &dot->z, angle->alpha_x);
	y_rotation(&dot->x, &dot->z, angle->alpha_y);
	z_rotation(&dot->x, &dot->y, angle->alpha_z);
}
