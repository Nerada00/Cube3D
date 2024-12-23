/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:56:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/07/02 11:17:59 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	count_color(char *tmp)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (tmp[0] != 'F' && tmp[0] != 'C')
		return (true);
	while (tmp[i])
	{
		if (tmp[i] == ',')
			j++;
		else if (tmp[i] != '\n' && !(tmp[i] >= '0' && tmp[i] <= '9')
			&& (!((tmp[i] > 8 && tmp[i] < 14) || tmp[i] == ' ')))
			return (false);
		i++;
	}
	if (j >= 3)
	{
		return (false);
	}
	else
		return (true);
}

bool	init_color(t_rgb **color, int i, char *tmp)
{
	char	*rgb;

	rgb = ft_strtok(tmp, ",");
	if (rgb == NULL)
		return (free(tmp), false);
	while (rgb != NULL && i <= 3)
	{
		if (i == 0)
			(*color)->green = ft_atoi(rgb);
		else if (i == 1)
			(*color)->red = ft_atoi(rgb);
		else if (i == 2)
			(*color)->blue = ft_atoi(rgb);
		rgb = ft_strtok(NULL, ", ");
		i++;
	}
	return (free(tmp), true);
}

bool	extract_color(t_rgb *color, char *line, int i, char c)
{
	char		*tmp;
	const int	len = ft_strlen(line) - find_path(line);
	const int	start = find_path(line);

	if (!count_color(line))
		return (free(line), false);
	while (line[i])
	{
		if (line[i] == c)
		{
			tmp = ft_substr(line, start, len - 1);
			break ;
		}
		i++;
	}
	free(line);
	return (init_color(&color, 0, tmp));
}

bool	recovery_colors(char *line, t_map **map, int i)
{
	static int	y;

	if (ft_strchr(line, 'F'))
	{
		if (!y)
			y = 0;
		if ((!((*map)->color_sol.blue < 0) || !((*map)->color_sol.green < 0)
				|| !((*map)->color_sol.red < 0)) && y > 2)
			return (free(line), false);
		(*map)->line_color = i;
		return (y++, extract_color(&(*map)->color_sol, line, 0, 'F'));
	}
	if (ft_strchr(line, 'C'))
	{
		if (!y)
			y = 0;
		if ((!((*map)->color_ceiling.blue < 0)
				|| !((*map)->color_ceiling.green < 0)
				|| !((*map)->color_ceiling.red < 0)) && y > 2)
			return (free(line), false);
		(*map)->line_color = i;
		return (y++, extract_color(&(*map)->color_ceiling, line, 0, 'C'));
	}
	return (false);
}

bool	is_init_color(t_map *map)
{
	if (map->color_sol.blue < 0 || map->color_sol.red < 0
		|| map->color_sol.green < 0 || map->color_ceiling.blue > 255
		|| map->color_ceiling.red > 255 || map->color_ceiling.green > 255)
		return (false);
	if (map->color_ceiling.blue < 0 || map->color_ceiling.red < 0
		|| map->color_ceiling.green < 0 || map->color_ceiling.blue > 255
		|| map->color_ceiling.red > 255 || map->color_ceiling.green > 255)
		return (false);
	if (map->color_ceiling.blue == map->color_sol.blue
		&& map->color_sol.red == map->color_ceiling.red
		&& map->color_sol.green == map->color_ceiling.green)
		return (false);
	return (true);
}
