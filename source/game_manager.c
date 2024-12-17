/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:44:00 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/16 12:44:02 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Init data before stat game	*/
int ft_init_game(char *map_file_name, game_manager_t **game_manager)
{
	*game_manager = malloc(sizeof(game_manager_t));
	if (!(*game_manager))
		return (perror("Error: Failed to allocate memory for game_manager\n"), -1);
	(*game_manager)->game_objs = malloc(sizeof(game_objs_t));
	if (!(*game_manager)->game_objs)
        return (perror("Error: Failed to allocate memory for game_objs\n"), -1);
	(*game_manager)->game_objs->player = malloc(sizeof(player_t));
	if (!(*game_manager)->game_objs->player)
		return (perror("Error: Failed to allocate memory for player\n"), -1);
	(*game_manager)->map = ft_map_loader(map_file_name);
	if (!(*game_manager)->map)
		return(-1);
	if (!ft_map_checker((*game_manager)->map))
		return (-1);
	(*game_manager)->resolution = ft_check_map_dimensions((*game_manager)->map);
	(*game_manager)->movements_count = 0;
	ft_img_init(*game_manager);
	(*game_manager)->game_objs->player->current_state = (*game_manager)->game_objs->player->player_D;
	(*game_manager)->mlx = mlx_init((*game_manager)->resolution[1] * 64,
		(*game_manager)->resolution[0] * 64, "so_long", 1);
	if (!(*game_manager)->mlx)
		return (perror("Error: Fails to init mlx\n"), -1);    
	return(1);
}

/* Init the all the loops to start playing	*/
void	ft_start_game(game_manager_t *game_manager)
{
	mlx_key_hook(game_manager->mlx, ft_key_handler, game_manager);
	mlx_loop(game_manager->mlx);
}

/*	TO DO Delete extra memory	*/
void	ft_free_game_manager(game_manager_t *game_manager)
{
	ft_printf(1, "ESCAPE\n");
	if (game_manager->map)
		ft_free_map(game_manager->map);
	mlx_close_window(game_manager->mlx);
	mlx_terminate(game_manager->mlx);
}

/* Load the different game images from image files	*/
void ft_img_init(game_manager_t *game_manager)
{
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
}

/* Checks that the given img exist or not	*/
void	ft_check_img(game_manager_t *game_manager, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;
	
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf(2, "Error: Can't load the file %s\n", path);
		ft_exit_game(game_manager);
	}
	ft_printf(2, "HOLA %s\n", path);
	*img = mlx_texture_to_image(game_manager->mlx, texture);
	if (!(*img))
	{
		ft_printf(2, "Error: Can't load the file %s\n", path);
		ft_exit_game(game_manager);
	}
	mlx_delete_texture(texture);
}
