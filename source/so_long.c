/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:48 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/09 10:45:46 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Simple handle imput function that checks for the key pressed down */
int	handle_input(int keysym, mlx_data *mlx_core)
{
	if (keysym == XK_Escape)
	{
		ft_printf(1, "The key %d (ESC) has been pressed\n", keysym);
		mlx_destroy_window(mlx_core->mlx_ptr, mlx_core->win_ptr),
		mlx_destroy_display(mlx_core->mlx_ptr), 
		free(mlx_core->mlx_ptr);
		exit(0);
	}
	ft_printf(1, "The key %d is pressed\n", keysym);
	return(0);
}

void print_map(char	**map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		ft_putstr(1, map[n]);
		n++;
	}
}

int	check_map(char	fd)
{
	char	*line;
	char	*map;
	int		i;
	int		map_size;

	i = 0;
	map_size = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	map = malloc(sizeof(char *) * i);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		free(line);
		i++;
	}
	print_map(map);
	return 0;
}

int	main(int argc, char **argv)
{
	// mlx_data	mlx_core;
	int			map_fd;

	if (argc == 2)
	{
		// mlx_core.mlx_ptr = mlx_init();
		// if (mlx_core.mlx_ptr == NULL)
		// 	return (perror("Error\n"), 1);
		map_fd = open(argv[1], O_RDONLY);
		if (map_fd == -1)
			return(perror("Error"), 1);
		check_map(map_fd);
		// mlx_core.win_ptr = mlx_new_window(mlx_core.mlx_ptr, 1920, 1080, "so_long");
		// if (mlx_core.win_ptr == NULL)
		// 	return(mlx_destroy_display(mlx_core.mlx_ptr), free(mlx_core.mlx_ptr), 
		// 			perror("Error\n"), 1);
		// mlx_key_hook(mlx_core.win_ptr, handle_input ,&mlx_core);
		// mlx_loop(mlx_core.mlx_ptr);
		// mlx_destroy_window(mlx_core.mlx_ptr, mlx_core.win_ptr);
		// mlx_destroy_display(mlx_core.mlx_ptr);
		// free(mlx_core.mlx_ptr);
	}
	return(0);
}
