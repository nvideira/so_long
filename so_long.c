/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:37:11 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/23 03:55:26 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//static int	ft_close(t_mlbx *mlbx)
//{
//	mlx_destroy_window(mlbx->mlx, mlbx->window);
//	exit(0);
//	return (0);
//}

void	ft_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}



int	main(int argc, char **argv)
{
	t_mlbx	mlbx;
	//t_img	img;
	//char	*path;

	if (argc != 2)
		ft_error("This program requires exactly 1 map to work.\n");
	mlbx.mlx = mlx_init();
	mlbx.map.matrix = read_map(argv[1], &mlbx.map);
	if (!mlbx.map.matrix)
		ft_error("Couldn't process the map.\n");
	if (!map_checks(mlbx.map))
		ft_error("Poorly constructed map.\n");
	mlbx.window = mlx_new_window(mlbx.mlx, 2000, 1250, "test window");
	//print_matrix(map.matrix);
	//ft_printf("height = %d\n", map.height);
	print_matrix(mlbx.map.matrix);






	//path = "./assets/zoro.xpm";
	//img.img = mlx_new_image(mlbx.mlx, 1540, 1080);
	//img.img = mlx_xpm_file_to_image(mlbx.mlx, path, &img.img_width, &img.img_height);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
	//mlx_pixel_put(mlbx.mlx, mlbx.window, x, y, 0x00FFEE00);
	//mlx_put_image_to_window(mlbx.mlx, mlbx.window, img.img, 0, 0);
	//mlx_hook(mlbx.window, 17, 0, ft_close, &mlbx);
	mlx_loop(mlbx.mlx);
	free_mat(mlbx.map.matrix);
}
