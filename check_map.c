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

int	wallborder(t_map map)
{
	int	i;
	int	size;
	int	j;

	i = -1;
	size = -1;
	while (++i < map.height)
	{
		if (size == -1)
			size = (int) ft_strlen(map.matrix[i]);
		else if (size != (int) ft_strlen(map.matrix[i]))
			return (0);
		if (map.matrix[i][0] != '1' || map.matrix[i][size - 1] != '1')
			return (0);
		j = -1;
		while ((i == 0 || i == map.height - 1) && map.matrix[i][++j])
		{
			if (map.matrix[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	fill_check(t_map map)
{
	int	i;
	int	j;

	i = 0;
	map.collect = 0;
	map.player = 0;
	map.door = 0;
	while (++i < map.height - 1)
	{
		j = -1;
		while (map.matrix[i][++j])
		{
			if (map.matrix[i][j] == 'C')
				map.collect++;
			else if (map.matrix[i][j] == 'P')
				map.player++;
			else if (map.matrix[i][j] == 'E')
				map.door++;
		}
	}
	if (map.collect > 0 && map.player > 0 && map.player < 2 && map.door > 0)
		return (1);
	return (0);
}

int	map_checks(t_map map)
{
	if (!wallborder(map))
		return (0);
	else if (!fill_check(map))
		return (0);
	else
		return (1);
}
