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
		if (dimensions[0] != 0 && (dimensions[0] != (int)ft_strlen(line)))
			return (free(line), free(dimensions), NULL);
		dimensions[0] = ft_strlen(line);
		dimensions[1]++;
		free(line);
	}
	if (!dimensions[1])
        return (free(dimensions), NULL);
	return(dimensions);
}

int	map_checker(char *map_file_name)
{
	int		map_fd;
	int		*dimensions;

	map_fd = open(map_file_name, O_RDONLY);
	if (map_fd == -1)
		return(perror("Error: Failed to open the map"), 0);
	dimensions = check_map_dimensions(map_fd);
	close(map_fd);
	if (!dimensions)
		return(perror("Error: Map is not rectangular or is empty\n"), 0);
	
	free(dimensions);
	return(1);
}