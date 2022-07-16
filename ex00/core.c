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

int	ft_is_index_friendly(int value, int **tab, int **index, int position, int size)
{
	int	x;
	int	y;

	x = position % size;
	y = position / size;
	printf("value = %d\n", value);

	if (y == 0)
	{
		printf("index = %d\n", index[0][x]);
		if ((index[0][x] == size && value != 1) || (index[0][x] == 1 && value != size))
			return (0);
	}
	if (y == size - 1)
	{
		printf("index = %d\n", index[1][x]);
		if ((index[1][x] == size && value != 1) || (index[1][x] == 1 && value != size))
			return (0);
	}
	if (x == 0)
	{
		printf("index = %d\n", index[2][y]);
		if ((index[2][y] == size && value != 1) || (index[2][y] == 1 && value != size))
			return (0);
	}
	if (x == size - 1)
	{
		printf("index = %d\n", index[3][y]);
		if ((index[3][y] == size && value != 1) || (index[3][y] == 1 && value != size))
			return (0);
	}
	printf("TRUE\n\n");
	return (1);
}

int	ft_is_valid(int **tab, int **index, int position, int size)
{
	int	value;

	if (position == size*size)
		return (1);

	int y = position / size, x = position % size;

	if (tab[y][x] != 0)
		return (ft_is_valid(tab, index, position + 1, size));

	value = 1;
	while (value <= size)
	{
		if (ft_is_not_in_row(value, tab, y, size) && ft_is_not_in_column(value, tab, x, size)
			&& ft_is_index_friendly(value, tab, index, position, size))
		{
			tab[y][x] = value;
			if (ft_is_valid(tab, index, position+1, size))
				return (1);
		}
		value++;
	}
	tab[y][x] = 0;

	return (0);
}
