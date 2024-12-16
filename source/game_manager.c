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
int init_game(char *map_file_name, game_manager_t **game_manager)
{
    *game_manager = malloc(sizeof(game_manager_t));
    if (!(*game_manager))
        return (perror("Error: Failed to allocate memory for game_manager\n"), -1);
    (*game_manager)->map = map_loader(map_file_name);
    if (!(*game_manager)->map)
        return(-1);
    if (!map_checker((*game_manager)->map))
        return (-1);
    (*game_manager)->resolution = check_map_dimensions((*game_manager)->map);
    (*game_manager)->mlx = mlx_init((*game_manager)->resolution[1] * 64,
        (*game_manager)->resolution[0] * 64, "so_long", 1);
	(*game_manager)->player_pos = find_start_point((*game_manager)->map, 
		(*game_manager)->resolution, (int []){0, 0});
    if (!(*game_manager)->mlx)
        return (perror("Error: Fails to init mlx\n"), -1);    
    return(1);
}

/* Init the all the loops to start playing	*/
void	start_game(game_manager_t *game_manager)
{
	mlx_key_hook(game_manager->mlx, key_handler, game_manager);
	mlx_loop(game_manager->mlx);
}

/*	TO DO Delete extra memory	*/
void	free_game_manager(game_manager_t *game_manager)
{
	ft_printf(1, "ESCAPE\n");
	if (game_manager->map)
		free_map(game_manager->map);
	mlx_close_window(game_manager->mlx);
	mlx_terminate(game_manager->mlx);
}
