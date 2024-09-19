/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:28:22 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/19 19:12:51 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((r(endcolor)) - (r(startcolor))) / (double)len;
	increment[1] = (double)((g(endcolor)) - (g(startcolor))) / (double)len;
	increment[2] = (double)((b(endcolor)) - (b(startcolor))) / (double)len;
	new[0] = (r(startcolor)) + ft_round(pix * increment[0]);
	new[1] = (g(startcolor)) + ft_round(pix * increment[1]);
	new[2] = (b(startcolor)) + ft_round(pix * increment[2]);
	newcolor = rgb(new[0], new[1], new[2]);
	return (newcolor);
}

void	iso_projection1(int x, int y, int z, t_data *data)
{
	int		center_x;
	int		center_y;
	double	angle;
	double	scale;
	double	height_adjustment;

	scale = data->scale;
	height_adjustment = data->dimension;
	angle = data->angle;
	center_y = HEIGHT / 2;
	center_x = WIDTH / 2;
	data->x_iso1 = (x - y) * cos(angle) * scale;
	data->y_iso1 = (x + y) * sin(angle) * scale - z * scale * height_adjustment;
	data->x_iso1 += center_x;
	data->y_iso1 += center_y;
}

void	iso_projection2(int x, int y, int z, t_data *data)
{
	int		center_x;
	int		center_y;
	double	angle;
	double	scale;
	double	height_adjustment;

	scale = data->scale;
	height_adjustment = data->dimension;
	angle = data->angle;
	center_y = HEIGHT / 2;
	center_x = WIDTH / 2;
	data->x_iso2 = (x - y) * cos(angle) * scale;
	data->y_iso2 = (x + y) * sin(angle) * scale - z * scale * height_adjustment;
	data->x_iso2 += center_x;
	data->y_iso2 += center_y;
}

t_data	*set_dxdy(t_data *data)
{
	data->dx = abs(data->x_iso2 - data->x_iso1);
	data->dy = abs(data->y_iso2 - data->y_iso1);
	data->sx = -1;
	if (data->x_iso1 < data->x_iso2)
		data->sx = 1;
	data->sy = -1;
	if (data->y_iso1 < data->y_iso2)
		data->sy = 1;
	return (data);
}
