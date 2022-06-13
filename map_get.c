/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:18:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/13 04:29:31 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ext_check(char *map_file)
{
	char			name[5];
	unsigned int	index;
	char			*map_verif;

	name[0] = '.';
	name[1] = 'b';
	name[2] = 'e';
	name[3] = 'r';
	name[4] = '\0';
	index = ft_strlen(map_file) - 4;
	map_verif = ft_substr(map_file, index, 5);
	if (!ft_strncmp(map_verif, name, 5))
		return (1);
	else
		return (0);
}

int	count_lines(char *file, t_map map)
{
	int		bytes;
	char	buffer[4096];
	char	*string;
	int		count;

	bytes = 1;
	count = 0;
	map.fd = open(file, O_RDONLY);
	while (bytes > 0)
	{
		bytes = read(map.fd, buffer, 4096);
		string = ft_strjoin(string, buffer);
	}
	while (*string)
	{
		if (*string == '\n')
			count++;
		string++;
	}
	free(string);
	close(map.fd);
	return (count);
}

char	**read_map(char *map_file, t_map *map)
{
	int	i;
	int	stop;

	i = 0;
	if (!ext_check(map_file))
		return (0);
	stop = count_lines(map_file, *map);
	map->fd = open(map_file, O_RDONLY);
	while (stop)
	{
		map->matrix[i] = get_next_line(map->fd);
		i++;
		stop--;
	}
	return (map->matrix);
}
