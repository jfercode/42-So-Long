/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:23:06 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/06 13:13:03 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER 'P'
# define EXIT 'E'
# define ENEMY 'I'
# define E_SPRITE game_manager->game_objs->enemy
# define EXIT_CLOSE '0'
# define EC_SPRITE game_manager->game_objs->exit_close
# define EXIT_OPEN '1'
# define EO_SPRITE game_manager->game_objs->exit_open
# define COLLECTIBLE 'C'
# define C_SPRITE game_manager->game_objs->collectable
# define WALL '1'
# define W_SPRITE game_manager->game_objs->wall
# define EMPTY '0'
# define F_SPRITE game_manager->game_objs->floor

# define PLAYER_GO game_manager->game_objs->player
# define PLAYER_STATE PLAYER_GO->current_state
# define PLAYER_X PLAYER_GO->player_pos[0]
# define PLAYER_Y PLAYER_GO->player_pos[1]
# define PLAYER_DIR PLAYER_GO->direction

# define UP "UP"
# define DOWN "DOWN"
# define RIGHT "RIGHT"
# define LEFT "LEFT"

# define TILE_SIZE 64

# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../source/ft_printf/include/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../source/ft_libft/include/libft.h"

typedef struct player
{
	mlx_image_t *current_state;
	mlx_image_t	*player_U[3];
	mlx_image_t	*player_D[3];
	mlx_image_t	*player_R[3];
	mlx_image_t	*player_L[3];
	int			*player_pos;
	int			animation_frame;
	char		*direction;
}					player_t;

typedef struct game_objs
{
	player_t		*player;

	mlx_image_t		*collectable;
	mlx_image_t		*exit_open;
	mlx_image_t		*exit_close;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*enemy;
	mlx_image_t		*movement_text;
	int				coll_count;
	int				exit_state;
}					game_objs_t;

typedef struct game_manager
{
	uint32_t	width;
	uint32_t	height;
	mlx_t		*mlx;
	game_objs_t	*game_objs;
	int			movements_count;
	int			*map_dimensions;
	char		**map;
}					game_manager_t;


void	ft_free_map(char **map);
void	ft_print_map(char **map);
void	ft_close_handler(void *param);

void	ft_win_game(game_manager_t *game_manager);
void	ft_init_mlx(game_manager_t *game_manager);
void	ft_img_init(game_manager_t *game_manager);
void	ft_start_game(game_manager_t *game_manager);
void	ft_render_game(game_manager_t *game_manager);
void	ft_render_static(game_manager_t *game_manager);
void	ft_render_dynamic(game_manager_t *game_manager);
void	ft_free_game_manager(game_manager_t *game_manager);
void	ft_loop_hook_handler(game_manager_t *game_manager);
void	ft_print_player_moves(game_manager_t *game_manager);
void	ft_render_player_moves(game_manager_t *game_manager);
void	ft_key_handler(struct mlx_key_data keydata, void *param);
void	ft_player_movement(mlx_key_data_t key, game_manager_t *game_manager);
void	ft_draw_image(game_manager_t *game_manager, mlx_image_t *img, int *pos);

int		ft_map_checker(char **map);
int		ft_obtain_map_lines(char *map_file_name);
int		ft_exit_game(game_manager_t *game_manager);
int		ft_check_map_extensions(char *map_file_name);
int		count_char(char **map, int *dimensions, char to_count);
int		ft_check_for_prop(char **map, int *dimensions, char prop_char);
int 	ft_init_game(char *map_file_name, game_manager_t **game_manager);

int		*ft_obtain_monitor_resolution();
int 	*ft_check_map_dimensions(char **map);
int		*ft_locate_player(char **map, int *dimensions);

char	*ft_get_next_line(int fd);
char	*ft_gnl_ft_strjoin(char *s1, char *s2);

char 	**ft_map_loader(char *map_file_name);
char	**ft_dup_map(char **map);

#endif /*SO_LONG_H*/
