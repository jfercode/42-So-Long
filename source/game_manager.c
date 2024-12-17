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
int	ft_init_game(char *map_file_name, game_manager_t **game_manager)
{
	*game_manager = malloc(sizeof(game_manager_t));
	if (!(*game_manager))
		return (perror("Error: Failed to mallox for game_manager\n"), -1);
	(*game_manager)->game_objs = malloc(sizeof(game_objs_t));
	if (!(*game_manager)->game_objs)
		return (perror("Error: Failed to malloc for game_objs\n"), -1);
	(*game_manager)->game_objs->player = malloc(sizeof(player_t));
	if (!(*game_manager)->game_objs->player)
		return (perror("Error: Failed to malloc for player\n"), -1);
	(*game_manager)->map = ft_map_loader(map_file_name);
	if (!(*game_manager)->map)
		return (-1);
	if (!ft_map_checker((*game_manager)->map))
		return (-1);
	(*game_manager)->resolution = ft_check_map_dimensions((*game_manager)->map);
	(*game_manager)->movements_count = 0;
	(*game_manager)->mlx = mlx_init((*game_manager)->resolution[1] * 64,
			(*game_manager)->resolution[0] * 64, "so_long", 1);
	if (!(*game_manager)->mlx)
		return (perror("Error: Fails to init mlx\n"), -1);
	ft_img_init(*game_manager);
	(*game_manager)->game_objs->player->current_state
		= (*game_manager)->game_objs->player->player_D;
	return (1);
}

/*	TO DO Delete extra memory to review at end of project */
void	ft_free_game_manager(game_manager_t *game_manager)
{
	ft_printf(1, "ESCAPE\n");
	if (game_manager->map)
		ft_free_map(game_manager->map);
	mlx_close_window(game_manager->mlx);
	mlx_terminate(game_manager->mlx);
}
