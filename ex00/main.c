/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:23:33 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 10:29:48 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	col_up[4];
	int	col_do[4];
	int	row_le[4];
	int	rox_ri[4];
	int	i;
	int	**tab;
	int	size;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	while (++i < 32)
	{
		if (i % 2 == 0)
		{
			if (i / 8 == 0)
				col_up[i % 8 / 2] = argv[1][i] - '0';
			if (i / 8 == 1)
				col_do[i % 8 / 2] = argv[1][i] - '0';
			if (i / 8 == 2)
				row_le[i % 8 / 2] = argv[1][i] - '0';
			if (i / 8 == 3)
				row_ri[i % 8 / 2] = argv[1][i] - '0';
			if (argv[1][i] > '4' || argv[1][i] < '0')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
	}
	size = 4;
	tab = ft_init_tab(tab, size);
	ft_edit_test_tab(tab, size);
	ft_print_tab(tab, size);
	ft_free_tab(tab, size);


	write(1, "Error\n", 6);
	return (0);
}
