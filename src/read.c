/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:06:07 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 11:24:16 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_list	*read_file(char *filepath)
{
	t_list	*list;
	t_list	*l;
	char	*line;
	int		fd;

	list = NULL;
	if ((fd = open(filepath, O_RDONLY)))
	{
		while (ft_get_next_line(fd, &line) > 0)
		{
			l = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
			ft_lstadd(&list, l);
			free(line);
		}
		if (list)
			return (list);
	}
	ft_putstr("no map or not readable");
	exit(EXIT_FAILURE);
}
