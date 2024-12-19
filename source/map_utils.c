/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:20 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 16:24:19 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Find the start point in a map */
int	*ft_locate_player(char **map, int *dimensions)
{
	int	*curr;

	curr = malloc(sizeof(int) * 2);
	curr[0] = 0;
	curr[1] = 0;
	while (curr[0] < dimensions[0])
	{
		while (curr[1] < dimensions[1])
		{
			if (map[curr[0]][curr[1]] == PLAYER)
				return (curr);
			curr[1]++;
		}
		curr[0]++;
		curr[1] = 0;
	}
	return (NULL);
}

/* Free the memory of a map */
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*	Check the dimensions and returns it	*/
int	*ft_check_map_dimensions(char **map)
{
	int		i;
	int		len;
	int		*dimensions;

	dimensions = malloc(sizeof(int) * 2);
	if (!dimensions)
		return (NULL);
	i = 0;
	dimensions[0] = 0;
	dimensions[1] = 0;
	while (map[i] != NULL)
	{
		len = 0;
		while (map[i][len] && map[i][len] != '\n')
			len++;
		if (dimensions[1] != 0 && (dimensions[1] != len))
			return (free(dimensions), NULL);
		if (dimensions[1] == 0)
			dimensions[1] = len;
		dimensions[0]++;
		i++;
	}
	if (!dimensions[0])
		return (free(dimensions), NULL);
	return (dimensions);
}

/*	Obtain the lines of the map */
int	ft_obtain_map_lines(char *map_file_name)
{
	int		map_fd;
	int		line_count;
	char	*line;

	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return (perror("Error: Failed to open the map"), 0);
	line = ft_get_next_line(map_fd);
	line_count = 1;
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = ft_get_next_line(map_fd);
	}
	close(map_fd);
	return (line_count);
}

/*	Load the map */
char	**ft_map_loader(char *map_file_name)
{
	int		i;
	int		map_fd;
	int		line_count;
	char	*line;
	char	**map;

	i = 0;
	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return (perror("Error: Failed to open the map"), NULL);
	line_count = ft_obtain_map_lines(map_file_name);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (perror("Error: Memory alloc falied\n"), close(map_fd), NULL);
	line = ft_get_next_line(map_fd);
	while (line != NULL)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = ft_get_next_line(map_fd);
	}
	map[i] = NULL;
	close (map_fd);
	return (map);
}
