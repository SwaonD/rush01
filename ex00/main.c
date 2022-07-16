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
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>




int	main(int argc, char **argv)
{
	int	i;
	int	**tab;
	int	**indexus;
	int	size;
	if (argc != 2)
	{
		write(1, "Errouuur\n", 6);
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	if (++i % 8 != 0 || i < 16 || i > 72)
	{
		write(1, "Errooor\n", 6);
		return (0);
	}
	size = i / 8;
	tab = ft_init_tab(tab, size, size);
	indexus = ft_init_index(argv[1], size);
	if (indexus == NULL)
		return(0);
	printf("%d\n", ft_is_valid(tab, indexus, 0, size));
	ft_print_tab(tab, size);
	ft_free_tab(tab, size);


	// write(1, "Error\n", 6);
	return (0);
}
