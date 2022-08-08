/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:41:04 by nvideira          #+#    #+#             */
/*   Updated: 2022/08/01 20:53:48 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	wallborder(t_mlbx *mlbx)
{
	int	i;
	int	size;
	int	j;

	i = -1;
	size = -1;
	while (++i < mlbx->map.height)
	{
		if (size == -1)
			size = (int) ft_strlen(mlbx->map.matrix[i]);
		else if (size != (int) ft_strlen(mlbx->map.matrix[i]))
			return (0);
		if (size > 15)
			ft_error("The map is too large for the screen.\n");
		if (mlbx->map.matrix[i][0] != '1' || mlbx->map.matrix[i][size - 1] != '1')
			return (0);
		j = -1;
		while ((i == 0 || i == mlbx->map.height - 1) && mlbx->map.matrix[i][++j])
		{
			if (mlbx->map.matrix[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	fill_check(t_mlbx *mlbx)
{
	int	i;
	int	j;

	i = 0;
	mlbx->map.collect = 0;
	mlbx->map.player = 0;
	mlbx->map.door = 0;
	while (++i < mlbx->map.height - 1)
	{
		j = -1;
		while (mlbx->map.matrix[i][++j])
		{
			if (mlbx->map.matrix[i][j] == 'C')
				mlbx->map.collect++;
			else if (mlbx->map.matrix[i][j] == 'P')
			{
				if (mlbx->map.player > 0)
					ft_error("This game is single player!\n");
				mlbx->map.player++;
			}
			else if (mlbx->map.matrix[i][j] == 'E')
			{
				if (mlbx->map.door > 0)
					ft_error("Too many exits!\n");
				mlbx->map.door++;
			}
			else if (mlbx->map.matrix[i][j] < '0' || mlbx->map.matrix[i][j] > '1')
				return (0);
		}
	}
	if (mlbx->map.collect > 0 && mlbx->map.player > 0 && mlbx->map.door > 0)
		return (1);
	return (0);
}

int	map_checks(t_mlbx *mlbx)
{
	if (!wallborder(mlbx))
		return (0);
	else if (!fill_check(mlbx))
		return (0);
	else
		return (1);
}
