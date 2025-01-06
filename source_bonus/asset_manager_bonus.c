/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:28 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/06 18:44:40 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	ft_check_img(game_manager, &game_manager->game_objs->player->player_U[0],
		"./assets/sprites/Player_U_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_U[1],
		"./assets/sprites/Player_U_2.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_U[2],
		"./assets/sprites/Player_U_3.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_D[0],
		"./assets/sprites/Player_D_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_D[1],
		"./assets/sprites/Player_D_2.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_D[2],
		"./assets/sprites/Player_D_3.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_L[0],
		"./assets/sprites/Player_L_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_L[1],
		"./assets/sprites/Player_L_2.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_L[2],
		"./assets/sprites/Player_L_3.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_R[0],
		"./assets/sprites/Player_R_1.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_R[1],
		"./assets/sprites/Player_R_2.png");
	ft_check_img(game_manager, &game_manager->game_objs->player->player_R[2],
		"./assets/sprites/Player_R_3.png");
}

static void	check_enemy_sprites(game_manager_t *game_manager)
{
	ft_check_img(game_manager, game_manager->game_objs->enemy[0], "./assets/sprites/Enemy_0.png");
	ft_check_img(game_manager, game_manager->game_objs->enemy[1], "./assets/sprites/Enemy_1.png");
	ft_check_img(game_manager, game_manager->game_objs->enemy[2], "./assets/sprites/Enemy_2.png");
	ft_check_img(game_manager, game_manager->game_objs->enemy[3], "./assets/sprites/Enemy_3.png");
	ft_check_img(game_manager, game_manager->game_objs->enemy[4], "./assets/sprites/Enemy_4.png");
	ft_check_img(game_manager, game_manager->game_objs->enemy[5], "./assets/sprites/Enemy_5.png");
}

/* Load the different game images from image files	*/
void	ft_img_init(game_manager_t *game_manager)
{
	if (!game_manager->game_objs)
		ft_printf(2, "Error: game_objs is NULL\n");
	check_player_sprites(game_manager);
	ft_check_img(game_manager, &C_SPRITE, "./assets/sprites/collectable.png");
	ft_check_img(game_manager, &F_SPRITE, "./assets/sprites/floor.png");
	ft_check_img(game_manager, &EO_SPRITE, "./assets/sprites/exit_open.png");
	ft_check_img(game_manager, &EC_SPRITE, "./assets/sprites/exit_close.png");
	ft_check_img(game_manager, &W_SPRITE, "./assets/sprites/wall.png");
	check_enemy_sprites(game_manager);
}

/* Simple resize and draw image */
void	ft_draw_image(game_manager_t *game_manager, mlx_image_t *img, int *pos)
{
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	mlx_image_to_window(game_manager->mlx, img, pos[0], pos[1]);
}
