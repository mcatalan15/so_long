/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/26 18:08:16 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(int argc, char **argv)
{
	(void)argc;
	(void)**argv;
	ft_printf("esto es checker");
	return (0);
}

void	helper(void)
{
	ft_printf("HOW TO PLAY SO_LONG:\n", "\tW:\n", "\tS\n", "\tA\n", "\tD\n");
}
