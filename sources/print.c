/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coords(t_dots **dot, t_fdf *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->i)
	{
		j = 0;
		while (j < ptr->j)
		{
			printf("x = %d, y = %d, z = %d, color = %x\n", dot[i][j].x,
					dot[i][j].y, dot[i][j].z, dot[i][j].color);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		printf("coord = %d, color = %x\n", tmp->coord, tmp->color);
		tmp = tmp->next;
	}
}
