/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:48 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/03 11:53:02 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	game_manager_t	*game_manager;

	game_manager = NULL;
	if (argc != 2)
		return (ft_printf(2, "Usage: %s <map_file>\n", argv[0]), -1);
	else if (argc == 2)
	{
		if (ft_init_game(argv[1], &game_manager) == -1)
			return ((ft_free_game_manager(game_manager)), -1);
		ft_start_game(game_manager);
	}
	return (0);
}
