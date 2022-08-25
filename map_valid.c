/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:57:03 by nvideira          #+#    #+#             */
/*   Updated: 2022/08/25 04:38:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	go_right(t_mlbx *mlbx, int *amount, char target)
{
	mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.x++;
	if (mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return is_valid(*mlbx, *amount, target);
	return (mlbx->valid);
}

int	go_down(t_mlbx *mlbx, int *amount, char target)
{
	mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.y++;
	if (mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return is_valid(*mlbx, *amount, target);
	return (mlbx->valid);
}
int	go_left(t_mlbx *mlbx, int *amount, char target)
{
	mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.x--;
	if (mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return is_valid(*mlbx, *amount, target);
	return (mlbx->valid);
}
int	go_up(t_mlbx *mlbx, int *amount, char target)
{
	mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.y--;
	if (mlbx->map.matrix[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return is_valid(*mlbx, *amount, target);
	return (mlbx->valid);
}

int	is_valid(t_mlbx mlbx, int amount, char target)
{
	printf("s %p\n", &(mlbx.map.matrix));
	while (amount > 0 && mlbx.valid != 1)
	{
		// printf("posicao--y-->%d\n", mlbx.coor.y);
		// printf("posicao--x-->%d\n\n", mlbx.coor.x);
		if (mlbx.map.matrix[mlbx.coor.y - 1][mlbx.coor.x] != '1' && mlbx.map.matrix[mlbx.coor.y - 1][mlbx.coor.x] != 'v')
			mlbx.valid = go_up(&mlbx, &amount, target);
		else if (mlbx.map.matrix[mlbx.coor.y][mlbx.coor.x - 1] != '1' && mlbx.map.matrix[mlbx.coor.y][mlbx.coor.x - 1] != 'v')
			mlbx.valid = go_left(&mlbx, &amount, target);
		else if (mlbx.map.matrix[mlbx.coor.y + 1][mlbx.coor.x] != '1' && mlbx.map.matrix[mlbx.coor.y + 1][mlbx.coor.x] != 'v')
			mlbx.valid = go_down(&mlbx, &amount, target);
		else if (mlbx.map.matrix[mlbx.coor.y][mlbx.coor.x + 1] != '1' && mlbx.map.matrix[mlbx.coor.y][mlbx.coor.x + 1] != 'v')
			mlbx.valid = go_right(&mlbx, &amount, target);
		else
			break ;
	}
	printf("valid: %d\n", mlbx.valid);
	printf("amount: %d\n\n", amount);
	return (mlbx.valid);
}
