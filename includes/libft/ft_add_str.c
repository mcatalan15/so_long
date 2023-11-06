/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:06 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/06 10:11:56 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function that add a given character to a given string */

void	ft_add_str(char *str, char character)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = character;
}
