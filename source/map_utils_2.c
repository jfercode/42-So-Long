/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:25:48 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 10:28:28 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

/*	Duplicates the map	*/
char	**ft_dup_map(char **map)
{
	int		i;
	int		*y;
	char	**dup_map;

	i = 0;
	y = ft_check_map_dimensions(map);
	dup_map = malloc(sizeof(char *) * (y[0] + 1));
	if (!dup_map)
		return (free(y), NULL);
	while (i < y[0])
	{
		dup_map[i] = ft_strdup(map[i]);
		if (!dup_map[i])
			return (ft_free_map(dup_map), free(y), NULL);
		i++;
	}
	dup_map[i] = NULL;
	free(y);
	return (dup_map);
}
