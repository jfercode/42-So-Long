/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:32:18 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 12:02:05 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Flood fill algorithm	*/
static void	fill(char **map, int *dimensions, int *curr, char to_fill)
{
	if ((curr[0] < 0 || curr[0] >= dimensions[0])
		|| (curr[1] < 0 || curr[1] >= dimensions[1]))
		return ;
	else if (map[curr[0]][curr[1]] == WALL || map[curr[0]][curr[1]] == 'X')
		return ;
	map[curr[0]][curr[1]] = 'X';
	fill(map, dimensions, (int []){curr[0] - 1, curr[1]}, to_fill);
	fill(map, dimensions, (int []){curr[0] + 1, curr[1]}, to_fill);
	fill(map, dimensions, (int []){curr[0], curr[1] - 1}, to_fill);
	fill(map, dimensions, (int []){curr[0], curr[1] + 1}, to_fill);
}

/*	Functions that count the n of char in a map	*/
int	count_char(char **map, int *dimensions, char to_count)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (i < dimensions[0])
	{
		if (map[i][j] == to_count)
			count++;
		if (j < dimensions[1] - 1)
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (count);
}

/*	Check for an available and unic exit in the map	*/
int	ft_check_for_prop(char **map, int *dimensions, char prop_char)
{
	int		num_props;
	int		num_find_props;
	int		*start_pos;
	char	**temp_map;

	temp_map = ft_dup_map(map);
	if (!temp_map)
		return (ft_printf(2, "Cannot check for prop %d\n", prop_char), 0);
	start_pos = ft_locate_player(temp_map, dimensions, (int []){0, 0});
	if (!start_pos)
		return (perror("Error: P not founded\n"), ft_free_map(temp_map), 0);
	num_props = count_char(temp_map, dimensions, prop_char);
	if (!num_props)
		return (ft_printf(2, "Error: No %c prop founded\n", prop_char),
			ft_free_map(temp_map), 0);
	fill(temp_map, dimensions, start_pos, prop_char);
	num_find_props = count_char(temp_map, dimensions, prop_char);
	if (num_find_props)
		return (ft_printf(2, "Error: Player can't reach the prop %c\n",
				prop_char), ft_free_map(temp_map), 0);
	ft_free_map(temp_map);
	return (1);
}
