/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:19:39 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/07 13:19:02 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Simple key handler to review what key is pressed */
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
	{
		ft_printf(1, "ESCAPE\n");
		ft_exit_game(game_manager);
	}
	if (keydata.key && keydata.action == MLX_PRESS)
		ft_player_movement(keydata, game_manager);
}

/*	Simple close handler to exit game when needed */
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
