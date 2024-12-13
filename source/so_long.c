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
	char		**map;
	int			*resolution;
	mlx_t		*mlx;
	// mlx_image_t	*textures; TO DO : Implementar texturas

	if (argc == 2)
	{
		map = map_loader(argv[1]);
		if (!map_checker(map))
			return (-1);
		resolution = check_map_dimensions(map);
		mlx = mlx_init(resolution[1] * 64,resolution[0] * 64, "so_long", 1);
		if (!mlx)
			return (perror("Error: Fails to init mlx\n"), -1);
		loop_hook_handler(mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free_map(map);
	}
	return (0);
}
