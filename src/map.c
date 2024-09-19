/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:13:14 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/14 13:26:42 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d_array(void **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map **map)
{
	t_map	*temp;

	while (*map != NULL)
	{
		free((*map)->line);
		temp = *map;
		*map = (*map)->next;
		free(temp);
	}
}

int	check_map(char *map_name)
{
	int		i;
	char	*file_ext;

	i = 0;
	while (map_name[i] != '\0')
	{
		if (map_name[i] == '.')
		{
			file_ext = ft_substr(map_name, i, ft_strlen(map_name));
			if (ft_strcmp(file_ext, ".fdf") == 0)
			{
				free(file_ext);
				return (1);
			}
			free(file_ext);
		}
		i++;
	}
	return (0);
}

t_map	*load_map(char *map_name)
{
	int		fd;
	char	*line;
	t_map	*map;
	t_map	*new;

	map = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("FDF: can't find or access %s\n", map_name);
		exit (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		ft_lstadd_back(&map, new);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
