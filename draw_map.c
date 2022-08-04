/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:31 by nvideira          #+#    #+#             */
/*   Updated: 2022/08/02 20:27:28 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// void    put_map(t_mlbx *mlbx)
// {
// 	int		y;
// 	int		x;

//     mlbx->path.img = mlx_xpm_file_to_image(mlbx->mlx, "./assets/grass(1).xpm", &mlbx->path.wid, &mlbx->path.hei);
// 	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
//     y = 0;
// 	while (y < mlbx->win_hei)
// 	{
// 		x = 0;
// 		while (x < mlbx->win_wid)
// 		{
// 			mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->path.img, x, y);
// 			x += 128;
// 		}
// 		mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->path.img, x, y);
// 		y += 128;
// 	}
// 	fill_map(mlbx);
// }

void    fill_map(t_mlbx *mlbx)
{
    // t_img	walltree;
	// t_img	player;
	//t_img	coll;
	int			y;
	int			x;
	static int	flag = 0;

	y = 0;
    mlbx->walltree.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/walltree.xpm", &mlbx->walltree.wid, &mlbx->walltree.hei);
	mlbx->player.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/zoro3.xpm", &mlbx->player.wid, &mlbx->player.hei);
	mlbx->path.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/grass(1).xpm", &mlbx->path.wid, &mlbx->path.hei);
	mlbx->coll.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/onigiri(1).xpm", &mlbx->coll.wid, &mlbx->coll.hei);
	mlbx->door.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/sunny(1).xpm", &mlbx->door.wid, &mlbx->door.hei);
	while (mlbx->map.matrix[y])
	{
		x = 0;
		while (mlbx->map.matrix[y][x])
		{
			if (mlbx->map.matrix[y][x] == '1')
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->walltree.img, x * 128, y * 128);
			else if (mlbx->map.matrix[y][x] == 'P')
			{
				if (flag == 0)
				{
					mlbx->player.x = x;
					mlbx->player.y = y;
					flag++;
				}
				ft_printf("y -->%d\n", mlbx->player.y);
				ft_printf("x-->%d\n", mlbx->player.x);
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->player.img, mlbx->player.x * 128, mlbx->player.y * 128);
			}
			else if (mlbx->map.matrix[y][x] == '0')
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->path.img, x * 128, y * 128);
			else if (mlbx->map.matrix[y][x] == 'C')
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->coll.img, x * 128, y * 128);
			else if (mlbx->map.matrix[y][x] == 'E')
				mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->door.img, x * 128, y * 128);
			x++;
		}
		y++;
	}
}