/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:48 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/19 14:23:04 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	game_manager_t	*game_manager;

	game_manager = NULL;
	if (argc != 2) 
		return (ft_printf(2, "Usage: %s <map_file>\n", argv[0]), -1);
	else if (argc == 2)
	{
		if (ft_init_game(argv[1], &game_manager) == -1)
            return (-1);
		ft_start_game(game_manager);
	}
	return (0);
}
