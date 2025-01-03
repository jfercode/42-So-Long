/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:39:49 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/03 11:52:52 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_render_game(game_manager_t *game_manager)
{
	ft_render_static(game_manager);
	ft_render_dynamic(game_manager);
}

void	ft_render_static(game_manager_t *game_manager)
{
	int32_t			pos[2];
	int				x;
	int				y;

	x = 0;
	while (game_manager->map[x])
	{
		y = 0;
		while (game_manager->map[x][y])
		{
			pos[0] = y * TILE_SIZE;
			pos[1] = x * TILE_SIZE;
			if (game_manager->map[x][y] == WALL)
				ft_draw_image(game_manager, W_SPRITE, pos);
			else if (game_manager->map[x][y] == EMPTY)
				ft_draw_image(game_manager, F_SPRITE, pos);
			else if (game_manager->map[x][y] == COLLECTIBLE)
				ft_draw_image(game_manager, C_SPRITE, pos);
			else if (game_manager->map[x][y] == ENEMY)
				ft_draw_image(game_manager, E_SPRITE, pos);
			y++;
		}
		x++;
	}
}

static void	ft_render_exit(game_manager_t *game_manager, int *pos)
{
	if (game_manager->game_objs->exit_state == EXIT_CLOSE)
		ft_draw_image(game_manager, EC_SPRITE, pos);
	else
		ft_draw_image(game_manager, EO_SPRITE, pos);
}

void	ft_render_dynamic(game_manager_t *game_manager)
{
	int32_t		pos[2];
	int			x;
	int			y;

	x = 0;
	while (game_manager->map[x])
	{
		y = 0;
		while (game_manager->map[x][y])
		{
			pos[0] = y * TILE_SIZE;
			pos[1] = x * TILE_SIZE;
			if (game_manager->map[x][y] == PLAYER)
				ft_draw_image(game_manager, PLAYER_STATE, pos);
			else if (game_manager->map[x][y] == EXIT)
				ft_render_exit(game_manager, pos);
			else if (game_manager->map[x][y] == EMPTY)
				ft_draw_image(game_manager, F_SPRITE, pos);
			y++;
		}
		x++;
	}
}
