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
	mlx_image_t *current_state;
	mlx_image_t	*player_U;
	mlx_image_t	*player_D;
	mlx_image_t	*player_R;
	mlx_image_t	*player_L;

	int			*player_pos;
}					player_t;

typedef struct game_objs
{
	player_t		*player;

	mlx_image_t		*collectable;
	mlx_image_t		*exit_open;
	mlx_image_t		*exit_close;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*background;

	int				coll_count;
	int				exit_state;
}					game_objs_t;

typedef struct game_manager
{
	int			movements_count;

	int			*resolution;

	char		**map;

	void		*game_windows;

	mlx_t		*mlx;
	player_t	*player;
	game_objs_t	*game_objs;
}					game_manager_t;


void	ft_free_map(char **map);
void	ft_print_map(char **map);
void	 ft_img_init(game_manager_t *game_manager);
void	ft_start_game(game_manager_t *game_manager);
void	ft_loop_hook_handler(game_manager_t *game_manager);
void	ft_free_game_manager(game_manager_t *game_manager);
void	ft_init_mlx(game_manager_t *game_manager);
void	ft_key_handler(struct mlx_key_data keydata, void *param);

int		ft_map_checker(char **map);
int		ft_obtain_map_lines(char *map_file_name);
int		ft_exit_game(game_manager_t *game_manager);
int		count_char(char **map, int *dimensions, char to_count);
int		ft_check_for_prop(char **map, int *dimensions, char prop_char);
int 	ft_init_game(char *map_file_name, game_manager_t **game_manager);

int		*ft_obtain_monitor_resolution();
int 	*ft_check_map_dimensions(char **map);
int		*ft_find_start_point(char **map, int *dimensions, int *curr);

char	*ft_get_next_line(int fd);
char	*ft_gnl_ft_strjoin(char *s1, char *s2);

char 	**ft_map_loader(char *map_file_name);
char	**ft_dup_map(char **map);

#endif /*SO_LONG_H*/