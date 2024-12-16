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

static int init_game(char *map_file_name, game_manager_t *game_manager)
{
	game_manager = malloc(sizeof(game_manager_t));
	game_manager->map = map_loader(map_file_name);
	if (!game_manager->map)
		return(-1);
	if (!map_checker(game_manager->map))
		return (-1);
	game_manager->resolution = check_map_dimensions(game_manager->map);
	game_manager->mlx = mlx_init(game_manager->resolution[1] * 64,
		game_manager->resolution[0] * 64, "so_long", 1);
	if (!game_manager->mlx)
		return (perror("Error: Fails to init mlx\n"), -1);	
	return(1);
}

int	main(int argc, char **argv)
{
	game_manager_t	*game_manager;

	game_manager = NULL;
	if (argc != 2) 
		return (ft_printf(2, "Usage: %s <map_file>\n", argv[0]), -1);
	else if (argc == 2)
	{
		init_game(argv[1], game_manager);
		mlx_key_hook(game_manager->mlx, key_handler, game_manager);
		mlx_loop(game_manager->mlx);
		free_game_manager(game_manager);
	}
	return (0);
}
