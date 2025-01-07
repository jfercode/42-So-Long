/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:29:43 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/07 09:42:11 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_animate_player_movement(game_manager_t *game_manager,
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

void	ft_animate_enemy(game_manager_t *game_manager, int32_t pos[2])
{
	static int	enemy_frame = 0;

	if (enemy_frame < 5)
		enemy_frame++;
	else
		enemy_frame = 0;
	ft_draw_image(game_manager,
		game_manager->game_objs->floor, pos);
	ft_draw_image(game_manager,
		game_manager->game_objs->enemy[enemy_frame], pos);
}
