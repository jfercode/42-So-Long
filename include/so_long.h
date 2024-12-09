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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../source/mlx_linux/mlx.h"
# include "../source/ft_printf/include/ft_printf.h"

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *s);

int	map_checker(char *map_file_name);

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif /*SO_LONG_H*/