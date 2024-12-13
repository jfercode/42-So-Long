/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:48 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/09 10:45:46 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	mlx_t	*mlx;

	if (argc == 2)
	{
		map = map_loader(argv[1]);
		if (!map_checker(map))
			return (-1);
		// print_map(map);
		mlx = mlx_init(2615, 1471, "so_long", 1);
		mlx->window = mlx_new_windows
		free_map(map);
	}
	return (0);
}
