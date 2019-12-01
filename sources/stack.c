/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:11:51 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/09 11:11:52 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stack		*stack_create_elem(int coord, int color)
{
	t_stack *tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	tmp->coord = coord;
	tmp->color = color;
	tmp->next = NULL;
	return (tmp);
}

int			stack_push_front(t_stack **begin_list, int coord, int color)
{
	t_stack *tmp;

	if (!(tmp = stack_create_elem(coord, color)))
		return (0);
	tmp->next = *begin_list;
	*begin_list = tmp;
	return (1);
}

void		free_stack(t_stack **begin_list)
{
	t_stack	*temp;
	t_stack	*list;

	list = *begin_list;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*begin_list = NULL;
}

int			read_line(int fd, t_fdf *ptr)
{
	char	*line;
	char	**array;
	int		j;
	int		tmp;

	line = NULL;
	if (((tmp = get_next_line(fd, &line)) <= 0))
		return (tmp);
	array = ft_strsplit(line, ' ');
	j = 0;
	while (array[j])
	{
		tmp = ft_atoi(array[j]);
		if (tmp < ptr->min)
			ptr->min = tmp;
		if (tmp > ptr->max)
			ptr->max = tmp;
		if (!(stack_push_front(&(ptr->stack), tmp, get_color(array[j]))))
			error("stack malloc error");
		j++;
	}
	free_arr((void **)array, j);
	ft_memdel((void **)&line);
	return (j);
}

int			reading(int fd, t_fdf *ptr)
{
	int		i;
	int		j;

	ptr->min = 0;
	ptr->max = 0;
	ptr->j = read_line(fd, ptr);
	i = 0;
	while ((j = read_line(fd, ptr)) > 0)
	{
		if (j != ptr->j)
			error("Found wrong line length. Exiting.");
		i++;
	}
	ptr->i = i;
	ptr->middle = (ptr->max + ptr->min) / 2;
	return (0);
}
