/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:16:32 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 16:38:01 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check_for_valid_tile(game_manager_t *game_manager, int x, int y)
{
	if (game_manager->map[y][x] == COLLECTIBLE)
		game_manager->game_objs->coll_count--;
	else if (game_manager->map[y][x] == WALL 
		|| (game_manager->map[y][x] == EXIT
		&& game_manager->game_objs->exit_state == EXIT_CLOSE))
		return (0);
	return (1);
}

void	ft_player_movement(struct mlx_key_data keydata,
		game_manager_t *game_manager)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		ft_update_map_with_player_movement(game_manager, 
			game_manager->game_objs->player->player_pos[0],
			game_manager->game_objs->player->player_pos[1] - 1);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_U;
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{	
		ft_update_map_with_player_movement(game_manager,
			game_manager->game_objs->player->player_pos[0],
			game_manager->game_objs->player->player_pos[1] + 1);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_D;
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{	
		ft_update_map_with_player_movement(game_manager,
			game_manager->game_objs->player->player_pos[0] - 1,
			game_manager->game_objs->player->player_pos[1]);
		game_manager->game_objs->player->current_state
				= game_manager->game_objs->player->player_L;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{	
		ft_update_map_with_player_movement(game_manager,
			game_manager->game_objs->player->player_pos[0] + 1,
			game_manager->game_objs->player->player_pos[1]);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_R;
	}
}

void	ft_update_map_with_player_movement(game_manager_t *game_manager, int x, int y)
{
	int	*player_pos;

	player_pos = game_manager->game_objs->player->player_pos;
	if (ft_check_for_valid_tile(game_manager, x, y))
	{
		game_manager->map[player_pos[1]][player_pos[0]] = EMPTY;
		game_manager->map[y][x] = PLAYER;
		player_pos[0] = x;
		player_pos[1] = y;
		game_manager->movements_count++;
	}
}
