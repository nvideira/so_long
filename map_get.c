/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:18:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/23 03:56:48 by nvideira         ###   ########.fr       */
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
	{
		free(map_verif);
		return (1);
	}
	else
	{
		free(map_verif);
		return (0);
	}
}

int	count_lines(char *file, t_map map)
{
	int		bytes;
	char	buffer[1];
	int		count;

	bytes = 1;
	count = 0;
	map.fd = open(file, O_RDONLY);
	while (bytes > 0)
	{
		bytes = read(map.fd, buffer, 1);
		if (buffer[0] == '\n')
			count++;
	}
	close(map.fd);
	return (count);
}

char	**trim_matrix(char **matrix, int height)
{
	int		i;
	char	*tmp;
	char	**new_matrix;

	i = 0;
	new_matrix = malloc(height * sizeof(char));
	while (i < height)
	{
		tmp = ft_substr(matrix[i], 0, ft_strlen(matrix[i]) - 1);
		new_matrix[i] = ft_strdup(tmp);
		//ft_printf("%s\n", new_matrix[i]);
		free(tmp);
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}

char	**read_map(char *map_file, t_map *map)
{
	int		i;
	int		stop;
	char	*tmp;
	char	**tmp_mat;

	i = 0;
	if (!ext_check(map_file))
		return (0);
	stop = count_lines(map_file, *map);
	map->fd = open(map_file, O_RDONLY);
	map->height = stop - 1;
	tmp_mat = malloc(stop * sizeof(char));
	while (stop > 1)
	{
		tmp = get_next_line(map->fd);
		tmp_mat[i] = ft_strdup(tmp);
		free(tmp);
		i++;
		stop--;
	}
	tmp_mat[i] = NULL;
	//printf("lineno: %d\n", stop);
	map->matrix = trim_matrix(tmp_mat, map->height);
	free(tmp_mat);
	return (map->matrix);
}
