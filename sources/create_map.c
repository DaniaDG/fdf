/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_map(t_fdf *ptr)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_color	c;

	tmp = ptr->stack;
	i = ptr->i;
	while (--i >= 0)
	{
		j = ptr->j;
		while (--j >= 0)
		{
			ptr->dot[i][j].x = j;
			ptr->dot[i][j].y = i;
			ptr->dot[i][j].z = tmp->coord;
			c.start = tmp->coord <= ptr->middle ? LOW_COLOR : CURRENT_COLOR;
			c.end = tmp->coord >= ptr->middle ? UP_COLOR : CURRENT_COLOR;
			if (ptr->keyboard->c_button == IS_PRESSED)
				ptr->dot[i][j].color = grad(tmp->coord, ptr->min, ptr->max, c);
			else
				ptr->dot[i][j].color = tmp->color != BACKGROUND ? tmp->color :
									grad(tmp->coord, ptr->min, ptr->max, c);
			tmp = tmp->next;
		}
	}
}
