/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:23:06 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/13 16:38:00 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

# define CELL_SIZE 32

# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../source/ft_printf/include/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../source/ft_libft/include/libft.h"

typedef struct player
{
	void	*player_U;
	void	*player_D;
	void	*player_R;
	void	*player_L;

	int		*player_pos;

}player_t;

typedef struct game_objs
{
	player_t	*player;

	void		*collectable;
	void		*exit_open;
	void		*exit_close;
	void		*wall;
	void		*floor;

	int			img_width;
	int			img_height;

}game_objs_t;

typedef struct game_manager
{
	int			movements_count;

	int			*resolution;

	char		**map;

	void		*game_windows;

	mlx_t		*mlx;
	player_t	*player;
	game_objs_t	*game_objs;

}game_manager_t;


void	free_map(char **map);
void	print_map(char **map);
void	start_game(game_manager_t *game_manager);
void	loop_hook_handler(game_manager_t *game_manager);
void	free_game_manager(game_manager_t *game_manager);
void	key_handler(struct mlx_key_data keydata, void *param);

int		map_checker(char **map);
int		obtain_map_lines(char *map_file_name);
int 	init_game(char *map_file_name, game_manager_t **game_manager);
int		check_for_prop(char **map, int *dimensions, char prop_char);

int 	*check_map_dimensions(char **map);
int		*find_start_point(char **map, int *dimensions, int *curr);

char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *s1, char *s2);

char 	**map_loader(char *map_file_name);
char	**dup_map(char **map);

#endif /*SO_LONG_H*/