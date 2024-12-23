/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:26 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 17:13:05 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Init the all the loops to start playing	*/
void	ft_start_game(game_manager_t *game_manager)
{
	game_manager->game_objs->coll_count = count_char(game_manager->map,
			game_manager->map_dimensions, COLLECTIBLE);
	game_manager->game_objs->exit_state = EXIT_CLOSE;
	game_manager->movements_count = 1;
	game_manager->game_objs->player->player_pos
		= ft_locate_player(game_manager->map, game_manager->map_dimensions);
	mlx_key_hook(game_manager->mlx, ft_key_handler, game_manager);
	mlx_close_hook(game_manager->mlx, ft_close_handler, game_manager);
	ft_render_game(game_manager);
	mlx_loop(game_manager->mlx);
}

/*	Win condition for end the game	*/
void	ft_win_game(game_manager_t *game_manager)
{
	ft_printf(1, "Congratulations! you caught the wild Pikachu\n");
	ft_free_game_manager(game_manager);
	exit (0);
}

/*	Simple function to end the game	*/
int	ft_exit_game(game_manager_t *game_manager)
{
	ft_printf(1, "I know, this game is too hard for you should you code it?\n");
	ft_free_game_manager(game_manager);
	exit (0);
	return (0);
}
