/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:51:03 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 12:13:51 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_not_in_column(int nb, int **tab, int column, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == tab[column][i])
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

int	ft_is_valid(int **tab, int position, int size)
{
	int	cell;

	if (position == size*size)
		return (1);

	int i = position / size, j = position % size;

	if (tab[i][j] != 0)
		return is_valid(tab, position + 1, size);

	cell = 0;
	while (cell <= size)
	{
		if (is_not_in_row(cell, tab, i, size) && is_not_in_column(cell, tab, j, size))
		{
			tab[i][j] = cell;

			if (is_valid(tab, position+1, size))
				return true;
		}
		cell++;
	}
	tab[i][j] = 0;

	return (0);
}
