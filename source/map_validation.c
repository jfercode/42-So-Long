/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:25:41 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/12 11:25:42 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		if (map[dimensions[0 - 1]][y] != WALL)
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

/*	Check that the maps has the minimal props to play */
static int	check_map_props(char **map, int *dimensions, int x, int y)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	while (x < dimensions[0])
	{
		while (y < dimensions[1])
		{
			if (map[x][y] == EXIT)
				e++;
			else if (map[x][y] == COLLECTIBLE)
				c++;
			else if (map[x][y] == PLAYER)
				p++;
			y++;
		}
		y = 0;
		x++;
	}
	if (e != 1 || c == 0 || p != 1)
		return (0);
	return (1);
}

/*	Map checker */
int	ft_map_checker(char **map)
{
	int		*dimensions;

	dimensions = ft_check_map_dimensions(map);
	if (!dimensions)
		return (free(dimensions),
			perror("Error: Map is not rectangular or is empty\n"), 0);
	if (!is_map_enclosed_by_walls(map, dimensions))
		return (ft_free_map(map), free(dimensions), 0);
	if (!check_map_props(map, dimensions, 0, 0))
		return (perror("Error: Map is impossible to play with it\n"),
			free(dimensions), ft_free_map(map), 0);
	if (!ft_check_for_prop(map, dimensions, EXIT)
		|| !ft_check_for_prop(map, dimensions, COLLECTIBLE))
		return (free(dimensions), ft_free_map(map), 0);
	free(dimensions);
	return (1);
}

/* Print the map */
void	ft_print_map(char **map)
{
	int	i;
	int	j;
	int	*dimensions;

	i = 0;
	dimensions = ft_check_map_dimensions(map);
	while (i < dimensions[0])
	{
		j = 0;
		while (j < dimensions[1])
		{
			ft_putchar(1, map[i][j]);
			j++;
		}
		ft_putchar(1, map[i][j]);
		i++;
	}
	free(dimensions);
}
