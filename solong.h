/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:36:57 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/13 04:20:35 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_struct{
	void	*mlx;
	void	*window;
}	t_mlbx;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_img;

typedef struct s_map{
	int		fd;
	int		height;
	int		width;
	char	**matrix;
}	t_map;

/*-------map_import.c--------*/

char	**read_map(char *map_file, t_map *map);

#endif
