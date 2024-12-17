/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:26 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/17 12:41:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

/*	Simple function to end the game	*/
int	ft_exit_game(game_manager_t *game_manager)
{
	ft_free_game_manager(game_manager);
	exit (0);
	return (0);
}