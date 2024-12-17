/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:26 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/17 12:41:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Init the all the loops to start playing	*/
void	ft_start_game(game_manager_t *game_manager)
{
	game_manager->game_objs->coll_count = count_char(game_manager->map,
			game_manager->resolution, COLLECTIBLE);
	game_manager->game_objs->exit_state = 0;
	game_manager->game_objs->player->player_pos 
		= ft_find_start_point(game_manager->map, game_manager->resolution,
		(int []) {0, 0});
	ft_print_map(game_manager->map);
	// ft_printf(1, "Player pos: %d.%d\n", game_manager->player->player_pos[0], game_manager->player->player_pos[1]);
	mlx_key_hook(game_manager->mlx, ft_key_handler, game_manager);
	mlx_loop(game_manager->mlx);
}

/*	Simple function to end the game	*/
int	ft_exit_game(game_manager_t *game_manager)
{
	ft_free_game_manager(game_manager);
	exit (0);
	return (0);
}
