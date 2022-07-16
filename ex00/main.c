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

int     main(int argc, char **argv)
{
        int     **tab;
        int     size;

        size = 4;
        tab = ft_init_tab(tab, size);
        ft_edit_test_tab(tab, size);
        ft_print_tab(tab, size);
        ft_free_tab(tab, size);
}
