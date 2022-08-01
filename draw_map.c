/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:31 by nvideira          #+#    #+#             */
/*   Updated: 2022/08/01 20:48:10 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    put_map(t_mlbx *mlbx)
{
    char	*path;
	int		y;
	int		x;
    t_img	img;

    path = "./assets/grass(1).xpm";
    img.img = mlx_xpm_file_to_image(mlbx->mlx, path, &img.wid, &img.hei);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
    y = 0;
	while (y < mlbx->win_hei)
	{
		x = 0;
		while (x < mlbx->win_wid)
		{
			mlx_put_image_to_window(mlbx->mlx, mlbx->window, img.img, x, y);
			x += 128;
		}
		mlx_put_image_to_window(mlbx->mlx, mlbx->window, img.img, x, y);
		y += 128;
	}
	fill_map(mlbx);
}

void    fill_map(t_mlbx *mlbx)
{
    t_img	walltree;
	int		y;
	int		x;

	y = 0;
    walltree.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/walltree.xpm", &walltree.wid, &walltree.hei);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
	while (mlbx->map.matrix[y])
	{
		x = 0;
		while (mlbx->map.matrix[y][x])
		{
			if (mlbx->map.matrix[y][x] == '1')
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, walltree.img, x * 128, y * 128);
			x++;
		}
		y++;
	}
}