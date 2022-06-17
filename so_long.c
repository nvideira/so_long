/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:37:11 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/17 04:36:32 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//static int	ft_close(t_mlbx *mlbx)
//{
//	mlx_destroy_window(mlbx->mlx, mlbx->window);
//	exit(0);
//	return (0);
//}





int	main(int argc, char **argv)
{
	//t_mlbx	mlbx;
	//t_img	img;
	t_map	map;
	int	i = 0;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments.\n"));
	map.matrix = read_map(argv[1], &map);
	if (!map.matrix)
		perror ("Error processing map");
	//mlbx.mlx = mlx_init();
	//while (map.matrix[i] != NULL)
	//{
	//	ft_printf("line %d--> ", i);
	//	ft_printf("%s\n", map.matrix[i]);
	//	i++;
	//}
	return (0);







	//path = "./Character.xpm";
	//mlbx.window = mlx_new_window(mlbx.mlx, 200, 200, "test window");
	////img.img = mlx_new_image(mlbx.mlx, 1540, 1080);
	//img.img = mlx_xpm_file_to_image(mlbx.mlx, path, &img_width, &img_height);
	////img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
	////mlx_pixel_put(mlbx.mlx, mlbx.window, x, y, 0x00FFEE00);
	//mlx_put_image_to_window(mlbx.mlx, mlbx.window, img.img, 0, 0);
	//mlx_hook(mlbx.window, 17, 0, ft_close, &mlbx);
	//mlx_loop(mlbx.mlx);
}
