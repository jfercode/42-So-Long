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

int	ft_exit_program(game_manager_t *game_manager)
{
	free_game_manager(game_manager);
	exit (0);
	return (0);
}

void	key_handler(struct mlx_key_data keydata, void *param)
{
	game_manager_t	*game_manager;

	game_manager = (game_manager_t *)param;
	if (!game_manager || !game_manager->mlx)
	{
		ft_printf(2, "Error: game_manager or game_manager->mlx is NULL\n");
		return ;
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit_program(game_manager);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		ft_printf(1, "UP\n");
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		ft_printf(1, "DOWN\n");
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		ft_printf(1, "RIGHT\n");
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		ft_printf(1, "LEFT\n");
}
