/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:28 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/03 14:06:38 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Checks that the given img exist or not	*/
static void	ft_check_img(game_manager_t *game_manager,
						mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf(2, "Error: Can't load the file %s\n", path);
		ft_exit_game(game_manager);
	}
	*img = mlx_texture_to_image(game_manager->mlx, texture);
	if (!(*img))
	{
		ft_printf(2, "Error: Can't load the file %s\n", path);
		ft_exit_game(game_manager);
	}
	mlx_delete_texture(texture);
}

// Load the different game imagess from image files for the player
static void	check_player_sprites(game_manager_t *game_manager)
{
	ft_check_img(game_manager, &game_manager->game_objs->player->player_U,
		"./assets/sprites/Player_U_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_D,
		"./assets/sprites/Player_D_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_L,
		"./assets/sprites/Player_L_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_R,
		"./assets/sprites/Player_R_1.png");
}

/* Load the different game images from image files	*/
void	ft_img_init(game_manager_t *game_manager)
{
	if (!game_manager->game_objs)
		ft_printf(2, "Error: game_objs is NULL\n");
	check_player_sprites(game_manager);
	ft_check_img(game_manager, &game_manager->game_objs->collectable,
		"./assets/sprites/collectable.png");
	ft_check_img(game_manager, &game_manager->game_objs->floor,
		"./assets/sprites/floor.png");
	ft_check_img(game_manager, &game_manager->game_objs->exit_open,
		"./assets/sprites/exit_open.png");
	ft_check_img(game_manager, &game_manager->game_objs->exit_close,
		"./assets/sprites/exit_close.png");
	ft_check_img(game_manager, &game_manager->game_objs->wall,
		"./assets/sprites/wall.png");
}

/* Simple resize and draw image */
void	ft_draw_image(game_manager_t *game_manager, mlx_image_t *img, int *pos)
{
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	mlx_image_to_window(game_manager->mlx, img, pos[0], pos[1]);
}
