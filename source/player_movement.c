/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:16:32 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/07 13:19:50 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check_for_valid_movement(game_manager_t *game_manager,
			int x, int y)
{
	if (game_manager->map[x][y] == WALL)
		return (0);
	else if (game_manager->map[x][y] == EXIT)
	{
		if (game_manager->game_objs->exit_state == EXIT_OPEN)
			return (ft_win_game(game_manager), 1);
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

static void	ft_move_player_to_position(game_manager_t *game_manager,
			int x, int y)
{
	if (ft_check_for_valid_movement(game_manager, x, y))
	{
		if (PLAYER_X == game_manager->exit_pos[0]
			&& PLAYER_Y == game_manager->exit_pos[1])
			game_manager->map[PLAYER_X][PLAYER_Y] = EXIT;
		else
			game_manager->map[PLAYER_X][PLAYER_Y] = EMPTY;
		PLAYER_X = x;
		PLAYER_Y = y;
		game_manager->map[x][y] = PLAYER;
		game_manager->movements_count++;
		ft_render_dynamic(game_manager);
		ft_print_player_moves(game_manager);
	}
}

void	ft_player_movement(struct mlx_key_data keydata,
		game_manager_t *game_manager)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		PLAYER_STATE = game_manager->game_objs->player->player_U;
		ft_move_player_to_position(game_manager, PLAYER_X - 1, PLAYER_Y);
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		PLAYER_STATE = game_manager->game_objs->player->player_D;
		ft_move_player_to_position(game_manager, PLAYER_X + 1, PLAYER_Y);
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		PLAYER_STATE = game_manager->game_objs->player->player_L;
		ft_move_player_to_position(game_manager, PLAYER_X, PLAYER_Y - 1);
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		PLAYER_STATE = game_manager->game_objs->player->player_R;
		ft_move_player_to_position(game_manager, PLAYER_X, PLAYER_Y + 1);
	}
}
