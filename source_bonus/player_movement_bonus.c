/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:16:32 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/06 18:16:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_check_for_valid_movement(game_manager_t *game_manager,
			int x, int y)
{
	if (game_manager->map[x][y] == WALL)
		return (0);
	else if (game_manager->map[x][y] == EXIT)
	{
		if (game_manager->game_objs->exit_state == EXIT_CLOSE)
			return (0);
		else
			return (ft_win_game(game_manager), 1);
	}
	else if (game_manager->map[x][y] == COLLECTIBLE)
	{
		game_manager->game_objs->coll_count--;
		if (game_manager->game_objs->coll_count == 0)
			game_manager->game_objs->exit_state = EXIT_OPEN;
		return (1);
	}
	else if (game_manager->map[x][y] == ENEMY)
		return (ft_exit_game(game_manager), 1);
	return (1);
}

static void	ft_move_player_to_position(game_manager_t *game_manager,
			int x, int y)
{
	if (ft_check_for_valid_movement(game_manager, x, y))
	{
		game_manager->map[PLAYER_X][PLAYER_Y] = EMPTY;
		PLAYER_X = x;
		PLAYER_Y = y;
		game_manager->map[x][y] = PLAYER;
		game_manager->movements_count++;
		ft_render_dynamic(game_manager);
	}
}

static void	ft_animate_player_movement(game_manager_t *game_manager,
		char *new_dir)
{
	if (ft_strncmp(PLAYER_DIR, new_dir, 5) != 0)
	{
		PLAYER_DIR = new_dir;
		PLAYER_GO->animation_frame = 0;	
	}
	else
	{
		if (PLAYER_GO->animation_frame == 0)
			PLAYER_GO->animation_frame = 1;
		else if (PLAYER_GO->animation_frame == 1)
			PLAYER_GO->animation_frame = 2;
		else if (PLAYER_GO->animation_frame == 2)
			PLAYER_GO->animation_frame = 1;
	}
	if (ft_strncmp(PLAYER_DIR, UP, 5) == 0)
		PLAYER_STATE = PLAYER_GO->player_U[PLAYER_GO->animation_frame];
	else if (ft_strncmp(PLAYER_DIR, DOWN, 5) == 0)
		PLAYER_STATE = PLAYER_GO->player_D[PLAYER_GO->animation_frame];
	else if (ft_strncmp(PLAYER_DIR, RIGHT, 5) == 0)
		PLAYER_STATE = PLAYER_GO->player_R[PLAYER_GO->animation_frame];
	else if (ft_strncmp(PLAYER_DIR, LEFT, 5) == 0)
		PLAYER_STATE = PLAYER_GO->player_L[PLAYER_GO->animation_frame];
}

void	ft_player_movement(struct mlx_key_data keydata,
		game_manager_t *game_manager)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		ft_animate_player_movement(game_manager, UP);
		ft_move_player_to_position(game_manager, PLAYER_X - 1, PLAYER_Y);
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		ft_animate_player_movement(game_manager, DOWN);
		ft_move_player_to_position(game_manager, PLAYER_X + 1, PLAYER_Y);
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		ft_animate_player_movement(game_manager, LEFT);
		ft_move_player_to_position(game_manager, PLAYER_X, PLAYER_Y - 1);
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		ft_animate_player_movement(game_manager, RIGHT);
		ft_move_player_to_position(game_manager, PLAYER_X, PLAYER_Y + 1);
	}
}
