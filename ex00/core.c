/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:51:03 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 14:52:09 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_not_in_column(int nb, int **tab, int column, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == tab[i][column])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_not_in_row(int nb, int **tab, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == tab[row][i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_index_friendly(int value, int **tab, int **index, int x, int y, int size)
{
	int	i;

	if (y == 0 || y == size - 1)
	{
		if (y == 0)
			i = 0;
		if (y == size)
			i = 1;
		if ((index[i][x] == 4 && value != 1) || (index[i][x] == 1 && value != 4))
			return (0);
	}
	if (x == 0 || x == size - 1)
	{
		if (x == 0)
			i == 2;
		if (x == size)
			i == 3;
		if ((index[i][y] == 4 && value != 1) || (index[i][y] == 1 && value != 4))
			return (0);
	}
	return (1);
}

int	ft_is_valid(int **tab, int **index, int position, int size)
{
	int	value;

	if (position == size*size)
		return (1);

	int y = position / size, x = position % size;

	if (tab[y][x] != 0)
		return (ft_is_valid(tab, position + 1, size));

	value = 1;
	while (value <= size)
	{
		if (ft_is_not_in_row(value, tab, y, size) && ft_is_not_in_column(value, tab, x, size)
			&& ft_is_index_friendly(value, tab, index, x, y, size))
		{
			tab[y][x] = value;
			if (ft_is_valid(tab, position+1, size))
				return (1);
		}
		value++;
	}
	tab[y][x] = 0;

	return (0);
}
