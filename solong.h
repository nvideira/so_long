/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:36:57 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/22 04:18:09 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		img_width;
	int		img_height;
	int		endian;
}	t_img;

typedef struct s_map{
	int		fd;
	int		height;
	int		width;
	char	**matrix;
	int		collect;
	int		player;
	int		door;
}	t_map;

typedef struct s_struct{
	void	*mlx;
	void	*window;
	int		win_wid;
	int		win_hei;
	t_map	map;
	t_map	img;
}	t_mlbx;

/*-------map_get.c--------*/

char	**read_map(char *map_file, t_map *map);

/*-------check_map.c-------*/

int		map_checks(t_map map);

/*-------extra.c----------*/

void	print_matrix(char **matrix);
void	free_mat(char **matrix);

#endif
