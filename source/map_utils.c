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

/* Check that the map is enclosed by walls */
static int	is_map_enclosed_by_walls(char **map, int *dimensions, int x, int y)
{
	if (map[x] == NULL)
		return (1);
	if (!(map[x][y] == '1' || map[x][y] == '0' || map[x][y] == 'E' 
		|| map[x][y] == 'P' || map[x][y] == 'C'))
			return (perror("Error: Invalid characters in map\n"), 0);
	if (y == 0 || y == dimensions[1] - 1) 
	{
		if (map[x][y] != '1')
			return (perror("Error: Map is not enclosed by walls\n"), 0);
	}
	else if (x == 0 || x == dimensions[0] - 1)
	{
		if (map[x][y] != '1')
			return (perror("Error: Map is not enclosed by walls\n"), 0);
    }
	if (y < dimensions[1] - 1)
        return is_map_enclosed_by_walls(map, dimensions, x, y + 1);
    return is_map_enclosed_by_walls(map, dimensions, x + 1, 0);
}


/*	Check that the maps has the minimal props to play	*/
static int	check_map_props(char **map, int *dimensions, 
							int x, int y, int e, int c, int p)
{
	if (map[x] == NULL)
	{
		if (e != 1)
			return (0);
		else if (c == 0)
			return (0);
		else if (p != 1)
			return (0);
		return (1);
	}
	if (map[x][y] == 'E')
		e++;
	else if (map[x][y] == 'C')
		c++;
	else if (map[x][y] == 'P')
		p++;
	if (y < dimensions[1] - 1)
        return check_map_props(map, dimensions, x, y + 1, e, c , p);
    return check_map_props(map, dimensions, x + 1, 0, e, c, p);
}

/*	Check the dimensions and returns it	*/
int* check_map_dimensions(int fd)
{
	int		*dimensions;
	char	*line;
	size_t	len;

	dimensions = malloc (sizeof(int) * 2);
	if (!dimensions)
		return (NULL);
	dimensions[0] = 0;
	dimensions[1] = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (dimensions[1] != 0 && (dimensions[1] != (int)len))
			return (free(line), free(dimensions), NULL);
		if (dimensions[1] == 0)
			dimensions[1] = (int)len;
		dimensions[0]++;
		free(line);
	}
	if (!dimensions[0])
		return (free(dimensions), NULL);
	return(dimensions);
}

/*	Map checker */
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
		return(0);
	if (!check_map_props(map, dimensions, 0, 0, 0, 0, 0))
		return(perror("Error: Map is impossible to play with it\n"), 0);
	if (!check_for_prop(map_file_name, dimensions, 'E') 
		|| !check_for_prop(map_file_name, dimensions, 'C'))
		return (0);
	free(dimensions);
	return(1);
}

/*	Load the map */
char **map_loader(char *map_file_name, int dimesions_y)
{
	int		i;
	int		map_fd;
	char	*line;
	char	**map;

	i = 0;
	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return(perror("Error: Failed to open the map"), NULL);
	map = malloc (sizeof(char *) * (dimesions_y + 1));
	while ((line = get_next_line(map_fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	return (map);
}