/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:26 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 16:21:45 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Init the all the loops to start playing	*/
void	ft_start_game(game_manager_t *game_manager)
{
	game_manager->game_objs->coll_count = count_char(game_manager->map,
			game_manager->map_dimensions, COLLECTIBLE);
	game_manager->game_objs->exit_state = EXIT_CLOSE;
	game_manager->movements_count = 0;
	game_manager->game_objs->player->player_pos = 
			ft_locate_player(game_manager->map, game_manager->map_dimensions);
	ft_printf(1, "dimensions: %d %d\n", game_manager->map_dimensions[0],
			game_manager->map_dimensions[1]);
	ft_printf(1, "player pos: %d %d\n", game_manager->game_objs->player->player_pos[0],
			game_manager->game_objs->player->player_pos[1]);	
	mlx_key_hook(game_manager->mlx, ft_key_handler, game_manager);
	mlx_close_hook(game_manager->mlx, ft_close_handler, game_manager);
	ft_render_game(game_manager);
	mlx_loop(game_manager->mlx);

}

/*	Simple function to end the game	*/
int	ft_exit_game(game_manager_t *game_manager)
{
	ft_free_game_manager(game_manager);
	exit (0);
	return (0);
}
