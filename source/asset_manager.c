/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:28 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 16:32:17 by jaferna2         ###   ########.fr       */
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

/* Load the different game images from image files	*/
void	ft_img_init(game_manager_t *game_manager)
{
	if (!game_manager->game_objs)
		ft_printf(2, "Error: game_objs is NULL\n");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_U,
		"./assets/sprites/player_up.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_D,
		"./assets/sprites/player_down.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_L,
		"./assets/sprites/player_left.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_R,
		"./assets/sprites/player_right.png");
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
	ft_check_img(game_manager, &game_manager->game_objs->background,
		"./assets/sprites/floor.png");
}

/* Simple resize and draw image */
void	ft_draw_image(game_manager_t *game_manager, mlx_image_t *img, int *pos)
{
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	mlx_image_to_window(game_manager->mlx, img, pos[0], pos[1]);
}

// //	Check and delete a image
// static void	ft_check_asset_to_erase(game_manager_t *game_manager,
// 						mlx_image_t **img)
// {
// 	if (*img)
// 	{
// 		mlx_delete_image(game_manager->mlx, *img);
// 		*img = NULL;
// 	}
// }

// //	Function to free all assets
// void	ft_free_asset(game_manager_t *game_manager)
// {
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->player->player_U);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->player->player_D);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->player->player_L);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->player->player_R);
// 	ft_check_asset_to_erase(game_manager, &PLAYER_STATE);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->collectable);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->floor);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->exit_open);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->exit_close);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->wall);
// 	ft_check_asset_to_erase(game_manager,
// 		&game_manager->game_objs->background);
// }
