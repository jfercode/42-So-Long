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
# include "../source/ft_libft/include/libft.h"
# include "../source/ft_printf/include/ft_printf.h"
# include "../source/codam_mlx_42/include/MLX42/MLX42.h"

void	free_map(char **map);
void	print_map(char **map);
void	loop_hook_handler(void *param);

int	map_checker(char **map);
int	obtain_map_lines(char *map_file_name);
int	check_for_prop(char **map, int *dimensions, char prop_char);

int* check_map_dimensions(char **map);
int	*find_start_point(char **map, int *dimensions, int *curr);

char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *s1, char *s2);

char **map_loader(char *map_file_name);

#endif /*SO_LONG_H*/