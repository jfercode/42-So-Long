/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:19:39 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/13 11:19:40 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	Simple key handler TO DO: Implement player movement here	*/
// void	*key_handler(game_manager_t *game_manager)
// {
// 	if (mlx_is_key_down(game_manager->mlx, MLX_KEY_ESCAPE))
// 	{
// 		ft_printf(1, "ESCAPE\n");
// 		mlx_close_window(game_manager->mlx);
// 	}
// 	else if (mlx_is_key_down(game_manager->mlx, MLX_KEY_UP) 
// 			|| mlx_is_key_down(game_manager->mlx, MLX_KEY_W))
// 		ft_printf(1, "UP\n");
// 	else if (mlx_is_key_down(game_manager->mlx, MLX_KEY_DOWN) 
// 			|| mlx_is_key_down(game_manager->mlx, MLX_KEY_S))
// 		ft_printf(1, "DOWN\n");
// 	else if (mlx_is_key_down(game_manager->mlx, MLX_KEY_RIGHT) 
// 			|| mlx_is_key_down(game_manager->mlx, MLX_KEY_D))
// 		ft_printf(1, "RIGHT\n");
// 	else if (mlx_is_key_down(game_manager->mlx, MLX_KEY_LEFT) 
// 			|| mlx_is_key_down(game_manager->mlx, MLX_KEY_A))
// 		ft_printf(1, "LEFT\n");
// 	return (0);
// }

void	key_handler(int keycode, game_manager_t * game_manager)
{
	if (keycode == MLX_KEY_ESCAPE)
	{
		ft_printf(1, "ESCAPE\n");
		mlx_close_window(game_manager->mlx);
	}
	else if (keycode == MLX_KEY_UP || keycode == MLX_KEY_ESCAPE)
		ft_printf(1, "UP\n");
	else if (keycode ==  MLX_KEY_DOWN || keycode ==  MLX_KEY_S)
		ft_printf(1, "DOWN\n");
	else if (keycode ==  MLX_KEY_RIGHT || keycode ==  MLX_KEY_D)
		ft_printf(1, "RIGHT\n");
	else if (keycode ==  MLX_KEY_LEFT || keycode ==  MLX_KEY_A)
		ft_printf(1, "LEFT\n");
}