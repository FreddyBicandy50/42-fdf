/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:05:54 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/19 19:24:11 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (matrix->matrix[i] != NULL)
	{
		free(matrix->matrix[i]);
		i++;
	}
	free(matrix->matrix);
	free(matrix);
}

void	free_program(t_data *data)
{
	if (!data)
		return ;
	if (data->mat)
		free_matrix(data->mat);
	if (data->map)
		free_map(&data->map);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

int	main(int argc, char *argv[])
{
	t_map		*map;
	t_data		*data;
	t_matrix	*matrix;

	map = NULL;
	matrix = NULL;
	data = NULL;
	if (argc <= 1 || argc > 2)
		ft_printf("FDF: too few arguments\n");
	else
	{
		if (!check_map(argv[1]))
		{
			ft_printf("FDF: map extension should be .fdf\n");
			return (1);
		}
		map = load_map(argv[1]);
		matrix = create_matrix(map, matrix);
		data = malloc(sizeof(t_data));
		data->map = map;
		data->mat = matrix;
		data = init(data);
		free_program(data);
	}
	return (0);
}
