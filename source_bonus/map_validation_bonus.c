/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:25:41 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/08 13:07:17 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/* Check that the map is enclosed by walls */
static int	is_map_enclosed_by_walls(char **map, int *dimensions)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < dimensions[1])
	{
		if (map[0][y] != WALL)
			return (perror("Error: Map is not enclosed by walls\n"), 0);
		if (map[dimensions[0] - 1][y] != WALL)
			return (perror("Error: Map is not enclosed by walls\n"), 0);
		y++;
	}
	while (x < dimensions[0])
	{
		if (map[x][0] != WALL)
			return (perror("Error: Map is not enclosed by walls\n"), 0);
		if (map[x][dimensions[1] - 1] != WALL)
			return (perror("Error: Map is not enclosed by walls\n"), 0);
		x++;
	}
	return (1);
}

// Check for valids characters in the map
static int	ft_check_for_valids_char_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != EXIT && map[i][j] != COLLECTIBLE
				&& map[i][j] != WALL && map[i][j] != PLAYER
				&& map[i][j] != ENEMY && map[i][j] != EMPTY)
			{
				if (ft_isalnum(map[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*	Check that the maps has the minimal props to play */
static int	check_map_props(char **map, int *dimensions)
{
	int	ex_count;
	int	c_count;
	int	p_count;
	int	en_count;

	ex_count = count_char(map, dimensions, EXIT);
	c_count = count_char(map, dimensions, COLLECTIBLE);
	p_count = count_char(map, dimensions, PLAYER);
	en_count = count_char(map, dimensions, ENEMY);
	if (ex_count != 1 || c_count == 0 || p_count != 1)
		return (0);
	return (ft_check_for_valids_char_in_map(map));
}

/* Check the map extension */
int	ft_check_map_extensions(char *map_file_name)
{
	char	*extension;
	char	*file_extension;

	extension = ".ber";
	file_extension = ft_strrchr(map_file_name, '.');
	if (!file_extension)
		return (perror("Error: Map file has no extension\n"), 0);
	else if (ft_strncmp(file_extension, extension, 4))
		return (perror("Error: Map file has wrong extension\n"), 0);
	return (1);
}

/*	Map checker */
int	ft_map_checker(char **map)
{
	int		*dimensions;

	dimensions = ft_check_map_dimensions(map);
	if (!dimensions)
		return (free(dimensions),
			perror("Error: Map is not valid to play with it\n"), 0);
	if (!is_map_enclosed_by_walls(map, dimensions))
		return (free(dimensions), 0);
	if (!check_map_props(map, dimensions))
		return (perror("Error: Map is not valid to play with it\n"),
			free(dimensions), 0);
	if (!ft_check_for_prop(map, dimensions, EXIT)
		|| !ft_check_for_prop(map, dimensions, COLLECTIBLE))
		return (free(dimensions), 0);
	free(dimensions);
	return (1);
}
