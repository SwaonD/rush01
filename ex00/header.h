/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addebadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:17 by addebadi          #+#    #+#             */
/*   Updated: 2022/07/16 10:28:35 by addebadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int **ft_init_tab(int **tab, int size);
void    ft_print_tab(int **tab, int size);
void    ft_free_tab(int **tab, int size);
int ft_is_not_in_column(int nb, int **tab, int column, int size);
int	ft_is_not_in_row(int nb, int **tab, int row, int size);
int	ft_is_valid(int tab, int position, int size);
