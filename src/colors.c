/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:27:51 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/19 19:13:39 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_round(double num)
{
	if (num >= 0.0)
		return ((int)num + 0.5);
	else
		return ((int)num - 0.5);
}

int	rgb(int a, int b, int c)
{
	return (((a) << 16) + ((b) << 8) + (c));
}

int	r(int a)
{
	return ((a) >> 16);
}

int	g(int a)
{
	return (((a) >> 8) & 0xFF);
}

int	b(int a)
{
	return ((a) & 0xFF);
}
