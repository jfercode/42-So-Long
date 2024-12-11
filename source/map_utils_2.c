/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:32:18 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/11 11:32:20 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Flood fill algorithm*/
void	fill(char **map, int *dimensions, int *curr, char to_fill)
{
	if ((curr[0] < 0 || curr[0] >= dimensions[0])
		|| (curr[1] < 0 || curr[1] >= dimensions[1]))
		return ;
	else if (map[curr[0]][curr[1]] == '1' || map[curr[0]][curr[1]] == '2')
		return ;
	if (map[curr[0]][curr[1]] == to_fill)
		map[curr[0]][curr[1]] = 'X';
	else if (map[curr[0]][curr[1]] == '0')
		map[curr[0]][curr[1]] = '2';
	fill(map, dimensions, (int []){curr[0] - 1, curr[1]}, to_fill);
	fill(map, dimensions, (int []){curr[0] + 1, curr[1]}, to_fill);
	fill(map, dimensions, (int []){curr[0], curr[1] - 1}, to_fill);
	fill(map, dimensions, (int []){curr[0], curr[1] + 1}, to_fill);
}

/* Functions that count the n of char in a map*/
int	count_char(char **map, int *dimensions, int *curr, char to_fill)
{
	static int	count = 0;
	int			result;

	result = 0;
	if (curr[0] >= dimensions[0])
	{
		result = count;
		count = 0;
		return (result);
	}
	if (map[curr[0]][curr[1]] == to_fill)
		count++;
	if (curr[1] < dimensions[1] - 1)
	{
		curr[1]++;
		return (count_char(map, dimensions, curr, to_fill));
	}
	curr[0]++;
	curr[1] = 0;
	return (count_char(map, dimensions, curr, to_fill));
}

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

/* Check for an available and unic exit in the map */
int	check_for_prop(char *map_file_name, int *dimensions, char prop_char)
{
	int		num_props;
	int		num_find_props;
	int		*start_pos;
	char	**temp_map;
	
	temp_map = map_loader(map_file_name, dimensions[1]);
	print_map(temp_map, dimensions);
	start_pos = find_start_point(temp_map, dimensions, (int[]){0, 0});
	if (!start_pos)
		return (perror("Error: Initial pos not founded\n"), 0);
	num_props = count_char(temp_map, dimensions, start_pos, prop_char);
	ft_printf(1, "chars %c counted: %d\n", prop_char, num_props);
	if (num_props < 1)
		return (ft_printf(2, "Error: No %c prop founded\n", prop_char), 0);
	start_pos = find_start_point(temp_map, dimensions, (int[]){0, 0});
	print_map(temp_map, dimensions);
	fill(temp_map, dimensions, start_pos, prop_char);
	start_pos = find_start_point(temp_map, dimensions, (int[]){0, 0});
	num_find_props = count_char(temp_map, dimensions, start_pos, 'X');
	if (num_props != num_find_props)
		return (ft_printf(2, "Error: Player can't reach the prop %c\n",
				prop_char), 0);
	return (1);
}
