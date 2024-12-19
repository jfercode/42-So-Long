/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:44:00 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 15:21:07 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Init data before stat game	TO DO free control here*/
int	ft_init_game(char *map_file_name, game_manager_t **game_manager)
{
	*game_manager = malloc(sizeof(game_manager_t));
	if (!(*game_manager))
		return (perror("Error: Failed to malloc for game_manager\n"), -1);
	(*game_manager)->game_objs = malloc(sizeof(game_objs_t));
	if (!(*game_manager)->game_objs)
		return (perror("Error: Failed to malloc for game_objs\n"), -1);
	(*game_manager)->game_objs->player = malloc(sizeof(player_t));
	if (!(*game_manager)->game_objs->player)
		return (perror("Error: Failed to malloc for player\n"), -1);
	if (!ft_check_map_extensions(map_file_name))
		return (-1);
	(*game_manager)->map = ft_map_loader(map_file_name);
	if (!(*game_manager)->map)
		return (-1);
	if (!ft_map_checker((*game_manager)->map))
		return (-1);
	(*game_manager)->map_dimensions
		= ft_check_map_dimensions((*game_manager)->map);
	ft_init_mlx(*game_manager);
	ft_img_init(*game_manager);
	(*game_manager)->game_objs->player->current_state
		= (*game_manager)->game_objs->player->player_D;
	return (1);
}

/*	TO DO Delete extra memory to review at end of project */
void	ft_free_game_manager(game_manager_t *game_manager)
{
	ft_printf(1, "ESCAPE\n");
	if (game_manager->map)
		ft_free_map(game_manager->map);
	mlx_close_window(game_manager->mlx);
	mlx_terminate(game_manager->mlx);
}

// Function to set the windows to the monitor size
void	ft_init_mlx(game_manager_t *game_manager)
{
	game_manager->width = game_manager->map_dimensions[1] * TILE_SIZE;
	game_manager->height = game_manager->map_dimensions[0] * TILE_SIZE;
	game_manager->mlx = mlx_init(game_manager->width,
			game_manager->height, "so_long", 1);
	if (!game_manager->mlx)
	{
		perror("Error: Fails to init mlx\n");
		return ;
	}
}
