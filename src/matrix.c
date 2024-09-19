/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:20:07 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/14 13:28:23 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*convert_to_int_array(char **string_array, int size)
{
	int	*int_array;
	int	i;

	int_array = malloc(size * sizeof(int));
	if (int_array == NULL)
	{
		ft_printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < size)
	{
		int_array[i] = ft_atoi(string_array[i]);
		i++;
	}
	return (int_array);
}

int	get_map_height(t_map *map)
{
	int	height;

	height = 0;
	while (map)
	{
		height++;
		map = map->next;
	}
	return (height);
}

int	count_elements(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

t_matrix	*create_matrix(t_map *map, t_matrix *matrix)
{
	int		i;
	char	**line_split;
	t_map	*temp;

	matrix = malloc(sizeof(t_matrix));
	matrix->height = get_map_height(map);
	matrix->matrix = malloc(sizeof(int *) * (matrix->height + 1));
	if (!matrix->matrix)
	{
		free(matrix);
		return (NULL);
	}
	i = 0;
	temp = map;
	while (temp)
	{
		line_split = ft_split(temp->line, ' ');
		matrix->width = count_elements(line_split);
		matrix->matrix[i] = convert_to_int_array(line_split, matrix->width);
		free_2d_array((void **)line_split);
		temp = temp->next;
		i++;
	}
	matrix->matrix[i] = NULL;
	return (matrix);
}
