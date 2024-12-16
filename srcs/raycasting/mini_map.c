/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:36:50 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/26 13:57:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_ceiling(t_map *map, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel_to_img(img, x, y, map->color_ceiling.red << 16 \
			| map->color_ceiling.green << 8 | map->color_ceiling.blue);
			x++;
		}
		y++;
	}
}

void	draw_sol(t_map *map, t_img *img)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel_to_img(img, x, y, map->color_sol.red << 16 \
			| map->color_sol.green << 8 | map->color_sol.blue);
			x++;
		}
		y++;
	}
}

static void	mapping(t_mlx *mlx, int i, int x, int y)
{
	int	color;
	int	j;

	if (mlx->map.map[y][x] == '1')
		color = 0xFFFFFF;
	else
		color = 0x000000;
	while (++i < 10)
	{
		j = -1;
		while (++j < 15)
		{
			mlx->pixel.pixel_x = x * 10 + i;
			mlx->pixel.pixel_y = y * 10 + j;
			if (mlx->pixel.pixel_x < WIDTH && mlx->pixel.pixel_y < HEIGHT)
				((int *)(mlx->img.addr))[mlx->pixel.pixel_y * WIDTH
					+ mlx->pixel.pixel_x] = color;
		}
	}
}

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map.map_height)
	{
		x = 0;
		while (x < mlx->map.map_width)
		{
			mapping(mlx, -1, x, y);
			x++;
		}
		y++;
	}
}
