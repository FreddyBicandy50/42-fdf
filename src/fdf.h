/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:59:58 by fbicandy          #+#    #+#             */
/*   Updated: 2024/09/16 22:35:49 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/Libft/libft.h"
# include "../libraries/minilib/mlx.h"
# include <X11/Xlib.h>
# include "X11/keysym.h"
# include "math.h"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_matrix
{
	int				width;
	int				height;
	int				**matrix;
}	t_matrix;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
	int			exit_flag;
	int			x_iso1;
	int			y_iso1;
	int			x_iso2;
	int			y_iso2;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			scale;
	double		dimension;
	double		angle;
	t_matrix	*mat;
	t_map		*map;
}	t_data;

# define WIDTH 1920
# define HEIGHT 1080

int			b(int a);
int			r(int a);
int			g(int a);
int			rgb(int a, int b, int c);
int			ft_round(double num);

int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		ft_lstadd_back(t_map **lst, t_map *new);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
t_map		*ft_lstnew(char *content);
char		*ft_strdup(const char *s);

t_map		*load_map(char *map_name);
int			check_map(char *map_name);
void		free_map(t_map **map);

t_matrix	*create_matrix(t_map *map, t_matrix *matrix);
int			get_map_height(t_map *map);
void		free_2d_array(void **array);

t_data		*init( t_data *data);

void		draw_map(t_matrix *matrix, t_data *data);
int			get_map_width(int *matrix);

void		iso_projection1(int x, int y, int z, t_data *data);
void		iso_projection2(int x, int y, int z, t_data *data);
t_data		*set_dxdy(t_data *data);

void		free_program(t_data *data);

int			key_pressed(int key, t_data *data);
int			gradient(int startcolor, int endcolor, int len, int pix);

#endif
