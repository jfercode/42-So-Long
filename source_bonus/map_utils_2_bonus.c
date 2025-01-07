/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:25:48 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/07 12:49:38 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

/* Find the exit point in a map */
int	*ft_locate_exit(char **map, int *dimensions)
{
	int	*curr;

	curr = malloc(sizeof(int) * 2);
	if (!curr)
		return (NULL);
	curr[0] = 0;
	curr[1] = 0;
	while (curr[0] < dimensions[0])
	{
		while (curr[1] < dimensions[1])
		{
			if (map[curr[0]][curr[1]] == EXIT)
				return (curr);
			curr[1]++;
		}
		curr[0]++;
		curr[1] = 0;
	}
	free (curr);
	return (NULL);
}
