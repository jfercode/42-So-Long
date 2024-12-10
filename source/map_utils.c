/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:20 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/09 16:03:21 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_map_enclosed_by_walls(char **map, int *dimensions, int x, int y)
{
	ft_printf(1, "%c", map[x][y]);
	if (x == dimensions[0])
		return (1);
	if (y == 0 || y == dimensions[1] - 1) 
	{
		if (map[x][y] != '1' && map[x][y] != '\n')
			return (0);
	}
	else if (x == 0 || x == dimensions[0] - 1)
	{
		if (map[x][y] != '1' && map[x][y] != '\n')
			return 0;
    }
	if (y < dimensions[1] - 1)
        return is_map_enclosed_by_walls(map, dimensions, x, y + 1);
    return is_map_enclosed_by_walls(map, dimensions, x + 1, 0);
}

static char **map_loader(char *map_file_name, int y)
{
	int		i;
	int		map_fd;
	char	*line;
	char	**map;

	i = 0;
	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return(perror("Error: Failed to open the map"), NULL);
	map = malloc (sizeof(char *) * (y + 1));
	while ((line = get_next_line(map_fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	return (map);
}

/*	Check the dimensions and returns it	*/
static int* check_map_dimensions(int fd)
{
	int		*dimensions;
	char	*line;

	dimensions = malloc (sizeof(int) * 2);
	if (!dimensions)
		return (NULL);
	dimensions[0] = 0;
	dimensions[1] = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (dimensions[1] != 0 && (dimensions[1] != (int)ft_strlen(line)))
			return (free(line), free(dimensions), NULL);
		dimensions[1] = ft_strlen(line);
		dimensions[0]++;
		free(line);
	}
	if (!dimensions[0])
        return (free(dimensions), NULL);
	return(dimensions);
}

/*	*/
int	map_checker(char *map_file_name)
{
	int		map_fd;
	int		*dimensions;
	char	**map;

	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return(perror("Error: Failed to open the map"), 0);
	dimensions = check_map_dimensions(map_fd);
	close(map_fd);
	if (!dimensions)
		return(perror("Error: Map is not rectangular or is empty\n"), 0);
	map = map_loader(map_file_name, dimensions[1]);
	if (!is_map_enclosed_by_walls(map, dimensions, 0, 0))
		return(perror("Error: Map is not enclosed by walls\n"), 0);
	free(dimensions);
	return(1);
}
