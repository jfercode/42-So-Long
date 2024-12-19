/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:19:39 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 16:34:51 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Simple key handler to review what key is pressed 
	- TO DO: Implement player movement here			*/
void	ft_key_handler(struct mlx_key_data keydata, void *param)
{
	game_manager_t	*game_manager;

	game_manager = (game_manager_t *)param;
	if (!game_manager || !game_manager->mlx)
	{
		ft_printf(2, "Error: game_manager or game_manager->mlx is NULL\n");
		return ;
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit_game(game_manager);
	if (keydata.key)
		ft_player_movement(keydata, game_manager);
	ft_printf(1, "Key pressed: %d\n", keydata.key);
	ft_render_game(game_manager);
}

void	ft_close_handler(void *param)
{
	game_manager_t	*game_manager;

	game_manager = (game_manager_t *)param;
	if (!game_manager || !game_manager->mlx)
	{
		ft_printf(2, "Error: game_manager or game_manager->mlx is NULL\n");
		return ;
	}
	ft_exit_game(game_manager);
}
