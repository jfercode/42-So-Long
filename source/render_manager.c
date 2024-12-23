/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:39:49 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/23 10:39:50 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
				ft_draw_image(game_manager, game_manager->game_objs->wall, pos);
			else if (game_manager->map[x][y] == EMPTY)
				ft_draw_image(game_manager, game_manager->game_objs->floor, pos);
			else if (game_manager->map[x][y] == COLLECTIBLE)
                ft_draw_image(game_manager, game_manager->game_objs->collectable, pos);
			y++;
		}
		x++;
	}
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
				ft_draw_image(game_manager, game_manager->game_objs->player->current_state, pos);           
			else if (game_manager->map[x][y] == EXIT)
			{
				if (game_manager->game_objs->exit_state == EXIT_CLOSE)
					ft_draw_image(game_manager, game_manager->game_objs->exit_close, pos);
				else
					ft_draw_image(game_manager, game_manager->game_objs->exit_open, pos);
			}
			else if (game_manager->map[x][y] == EMPTY)
				ft_draw_image(game_manager, game_manager->game_objs->floor, pos);
			y++;
		}
		x++;
	}
}
