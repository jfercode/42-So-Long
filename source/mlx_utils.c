/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:40 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/09 12:36:41 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../include/so_long.h"

/* Places a pixel with a specific color at a 
	given position in an image stored in memory. */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * data->bits_per_pixel / 8 );
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}