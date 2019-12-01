/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_fdf		*ptr;

	errno = 0;
	if (!(ptr = (t_fdf *)malloc(sizeof(t_fdf))))
		error("init error");
	ptr->stack = NULL;
	if (argc != 2)
		error("Usage : ./fdf <filename>");
	fd = open(argv[1], O_WRONLY);
	if (fd < 0 && errno == 21)
		error("reading error");
	if (((fd = open(argv[1], O_RDONLY))) < 0)
		error("open file error");
	if ((reading(fd, ptr)) < 0)
		error("reading error");
	init_fdf(ptr);
	draw(ptr);
	hooks(ptr);
	return (0);
}
