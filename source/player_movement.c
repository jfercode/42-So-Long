/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:16:32 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 17:18:36 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int ft_check_for_valid_movement(game_manager_t *game_manager, int x, int y)
{
	if (game_manager->map[x][y] == WALL)
		return (0);
	else if (game_manager->map[x][y] == EXIT)
	{
		if (game_manager->game_objs->exit_state == EXIT_CLOSE)
			return (0);
		else 
			return (1); // TO DO: Add the condition to win the game	here
	}
	else if (game_manager->map[x][y] == COLLECTIBLE)
	{
		game_manager->game_objs->coll_count--;
		if (game_manager->game_objs->coll_count == 0)
			game_manager->game_objs->exit_state = EXIT_OPEN;
		return (1);
	}
	return (1);
}

static void	ft_move_player_to_position(game_manager_t *game_manager, int x, int y)
{
	if (ft_check_for_valid_movement(game_manager, x, y))
	{
		game_manager->map[game_manager->game_objs->player->player_pos[0]]
			[game_manager->game_objs->player->player_pos[1]] = EMPTY;
		game_manager->game_objs->player->player_pos[0] = x;
		game_manager->game_objs->player->player_pos[1] = y;
		game_manager->map[x][y] = PLAYER;
		game_manager->movements_count++;
	}
}

void	ft_player_movement(struct mlx_key_data keydata,
		game_manager_t *game_manager)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		ft_move_player_to_position(game_manager, game_manager->game_objs->player->player_pos[0] - 1,
			game_manager->game_objs->player->player_pos[1]);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_U;
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{	
		ft_move_player_to_position(game_manager, game_manager->game_objs->player->player_pos[0] + 1,
			game_manager->game_objs->player->player_pos[1]);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_D;
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{	
		ft_move_player_to_position(game_manager, game_manager->game_objs->player->player_pos[0],
			game_manager->game_objs->player->player_pos[1] - 1);
		game_manager->game_objs->player->current_state
				= game_manager->game_objs->player->player_L;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		ft_move_player_to_position(game_manager, game_manager->game_objs->player->player_pos[0],
			game_manager->game_objs->player->player_pos[1] + 1);
		game_manager->game_objs->player->current_state
			= game_manager->game_objs->player->player_R;
	}
}


