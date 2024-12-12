/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:23:06 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/05 10:23:07 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../source/mlx_linux/mlx.h"
# include "../source/ft_printf/include/ft_printf.h"
# include "../source/ft_libft/include/libft.h"

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;	
}				mlx_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void free_map(char **map);
void	print_map(char **map, int *dimensions);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	map_checker(char *map_file_name);
int	check_for_prop(char *map_file_name, int *dimensions, char prop_char);

int	*find_start_point(char **map, int *dimensions, int *curr);

char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *s1, char *s2);

char **map_loader(char *map_file_name, int dimesions_y);

#endif /*SO_LONG_H*/