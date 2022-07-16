/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:23:33 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 14:32:56 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*ft_init_parambuff(int *tab, int size)
{
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int	i;
	int	**tab;
	int	size;
	int	*col_up;
	int	*col_do;
	int	*row_le;
	int	*row_ri;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	while (argv[1][i])
		i++;
	if (++i % 8 != 0 || i < 16 || i > 72)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = i / 8;
	ft_init_parambuff(col_up, size);
	ft_init_parambuff(col_do, size);
	ft_init_parambuff(row_le, size);
	ft_init_parambuff(row_ri, size);
	i = -1;
	while (++i < size * 8)
	{
		if (i % 2 == 0)
		{
			if (i / (size * 2) == 0)
				col_up[i % (size * 2) / 2] = argv[1][i] - '0';
			if (i / (size * 2) == 1)
				col_do[i % (size * 2) / 2] = argv[1][i] - '0';
			if (i / (size * 2) == 2)
				row_le[i % (size * 2) / 2] = argv[1][i] - '0';
			if (i / (size * 2) == 3)
				row_ri[i % (size * 2) / 2] = argv[1][i] - '0';
			if (argv[1][i] > size + '0' || argv[1][i] < '0')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
	}
	// size = 4;
	tab = ft_init_tab(tab, size);
	ft_print_tab(tab, size);
	ft_free_tab(tab, size);


	write(1, "Error\n", 6);
	return (0);
}
