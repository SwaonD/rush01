/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:09:16 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 10:24:40 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	**ft_init_tab(int **tab, int rows, int size)
{
	int	i;
	int	y;

	i = 0;
	tab = malloc(size * sizeof(int*));
	while (i < rows)
	{
		tab[i] = malloc(size * sizeof(int));
		y = 0;
		while (y < size)
		{
			tab[i][y] = 0;
			y++;
		}
		i++;
	}
	return (tab);
}

int	**ft_init_index(char *arg1, int size)
{
	int	i;
	int	**indexus;

	i = -1;
	indexus = ft_init_tab(indexus, 4, size)
	while (++i < size * 8)
	{
		if (i % 2 == 0)
		{
			if (arg1[i] > size + '0' || arg1[i] < '0')
			{
				write(1, "Error\n", 6);
				return (NULL);
			}
			indexus[i / (size * 2)][i % (size * 2) / 2] = arg1[i] - '0';
		}
	}
	return (indexus);
}

void	ft_print_tab(int **tab, int size)
{
	int	i;
	int	y;

	i = 0;
	while (i < size)
	{
		y = 0;
		while (y < size)
		{
			ft_putchar(tab[i][y] + '0');
			ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
