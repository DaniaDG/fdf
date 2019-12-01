/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:29:24 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/01 14:57:48 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		convert_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (-1);
}

int				get_color(char *str)
{
	int		red;
	int		green;
	int		blue;

	if (!(str = ft_strchr(str, 'x')))
		return (BACKGROUND);
	str++;
	red = convert_digit(*str) * 16 + convert_digit(*(str + 1));
	str += 2;
	green = convert_digit(*str) * 16 + convert_digit(*(str + 1));
	str += 2;
	blue = convert_digit(*str) * 16 + convert_digit(*(str + 1));
	return ((red << 16) | (green << 8) | blue);
}

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				grad(int current, int min, int max, t_color color)
{
	int		r;
	int		g;
	int		b;
	double	k;

	k = percent(min, max, current);
	r = (int)(red(color.start) + (red(color.end) - red(color.start)) * k);
	g = (int)(green(color.start) + (green(color.end) - green(color.start)) * k);
	b = (int)(blue(color.start) + (blue(color.end) - blue(color.start)) * k);
	return (rgb(r, g, b));
}

int				get_color_grad(t_dots current, t_dots start, t_dots end,
							t_dots delta)
{
	t_color	color;

	color.start = start.color;
	color.end = end.color;
	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		return (grad(current.x, start.x, end.x, color));
	return (grad(current.y, start.y, end.y, color));
}
