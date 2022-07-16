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

int	**ft_init_tab(int **tab, int size)
{
	int	i;
	int	y;

	i = 0;
	tab = malloc(size * sizeof(int*));
	while (i < size)
	{
		tab[i] = malloc(size * sizeof(int));
		y = 0;
		while (y < size)
		{
			tab[i][y] = '0';
			y++;
		}
		i++;
	}
	return (tab);
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
			write(1, &tab[i][y], 1);
			write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
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
