/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:29:58 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/16 22:29:15 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_data *data)
{
	free_program(data);
	exit(EXIT_SUCCESS);
}

void	render(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img_ptr)
		exit(EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data->mat, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}

void	view(int key, t_data *data)
{
	if (key == XK_Up)
	{
		data->dimension += 0.1;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
	else if (key == XK_Down)
	{
		if (data->dimension > 0.1)
			data->dimension -= 0.1;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
	if (key == XK_a)
	{
		data->angle -= M_PI / 30;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
	else if (key == XK_d)
	{
		data->angle += M_PI / 30;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
}

int	key_pressed(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data);
	else if (key == XK_KP_Add)
	{
		data->scale ++;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
	else if (key == XK_KP_Subtract)
	{
		if (data->scale > 1)
			data->scale --;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		render(data);
	}
	else
		view(key, data);
	return (0);
}

t_data	*init(t_data *data)
{
	data->scale = 15;
	data->angle = M_PI / 6;
	data->dimension = 0.1;
	data->color = 0xFFFFFF;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (!data->win_ptr)
		exit(EXIT_FAILURE);
	render(data);
	mlx_key_hook(data->win_ptr, key_pressed, data);
	mlx_loop(data->mlx_ptr);
	return (data);
}
