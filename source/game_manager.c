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

void	free_game_manager(game_manager_t *game_manager)
{
	if (game_manager->game_windows)
		free(game_manager->game_windows);
	if (game_manager->map)
		free_map(game_manager->map);
	if (game_manager->resolution)
		free(game_manager->resolution);
	if (game_manager->mlx)	
 		mlx_terminate(game_manager->mlx);
}
