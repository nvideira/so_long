/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:02:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/08/10 18:45:13 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	load_imgs(t_mlbx *mlbx)
{
	mlbx->walltree.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/walltree.xpm",
			&mlbx->walltree.wid, &mlbx->walltree.hei);
	mlbx->player.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/zoro3.xpm",
			&mlbx->player.wid, &mlbx->player.hei);
	mlbx->path.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/grass(1).xpm",
			&mlbx->path.wid, &mlbx->path.hei);
	mlbx->coll.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/onigiri(1).xpm",
			&mlbx->coll.wid, &mlbx->coll.hei);
	mlbx->door.img = mlx_xpm_file_to_image(mlbx->mlx, "assets/sunny(1).xpm",
			&mlbx->door.wid, &mlbx->door.hei);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%s", matrix[i]);
		i++;
	}
}

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
