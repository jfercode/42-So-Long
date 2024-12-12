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

/* Print the map */
void	print_map(char **map, int *dimensions)
{
	int i;
	int j;

	i = 0;
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
	ft_putchar(1, '\n');
}

/* Find the start point in a map */
int	*find_start_point(char **map, int *dimensions, int *curr)
{
	if (map[curr[0]][curr[1]] == 'P')
		return (curr);
	else if (curr[0] >= dimensions[0])
		return (NULL);
	if (curr[1] < dimensions[1] -1)
	{
		curr[1]++;
		return (find_start_point(map, dimensions, curr));
	}
	curr[0]++;
    curr[1] = 0;
	return (find_start_point(map, dimensions, curr));
}

/* Free the memory of a map */
void free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
		free(line);
		i++;
	}
	map[i] = NULL;
	return (map);
}