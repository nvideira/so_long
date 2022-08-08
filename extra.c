/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:02:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/22 03:04:22 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_ad_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char )c && s[i] != '\0')
		i++;
	if (s[i] == (char )c)
		return (i);
	else
		return (0);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
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
