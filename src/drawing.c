/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:48:01 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/16 22:25:28 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_width(int *matrix_row)
{
	int	i;

	i = 0;
	while (matrix_row[i] != '\0')
		i++;
	return (i);
}

void	put_pixel(t_data *data)
{
	int	*img_data;

	if (data->x_iso1 >= 0 && data->x_iso1 < 1920
		&&data->y_iso1 >= 0 && data->y_iso1 < 1080)
	{
		data->color = gradient(0xfefefe, 0x00ff00, data->dx, data->dy);
		img_data = (int *)data->addr;
		img_data[data->y_iso1 * data->line_length / 4
			+ data->x_iso1] = data->color;
	}
}

void	draw_line(t_data *data)
{
	int	err;
	int	er2;

	data = set_dxdy(data);
	err = data->dx - data->dy;
	while (1)
	{
		put_pixel(data);
		if (data->x_iso1 == data->x_iso2 && data->y_iso1 == data->y_iso2)
			break ;
		er2 = err * 2;
		if (er2 > -data->dy)
		{
			err -= data->dy;
			data->x_iso1 += data->sx;
		}
		if (er2 < data->dx)
		{
			err += data->dx;
			data->y_iso1 += data->sy;
		}
	}
}

void	draw_map(t_matrix *matrix, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < matrix->height)
	{
		x = 0;
		while (x < matrix->width)
		{
			iso_projection1(x, y, matrix->matrix[y][x], data);
			if (x + 1 < matrix->width)
			{
				iso_projection2(x + 1, y, matrix->matrix[y][x + 1], data);
				draw_line(data);
			}
			if (y + 1 < matrix->height)
			{
				iso_projection2(x, y + 1, matrix->matrix[y + 1][x], data);
				draw_line(data);
			}
			x++;
		}
		y++;
	}
}
