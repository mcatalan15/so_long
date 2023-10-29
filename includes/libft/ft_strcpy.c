/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:35:42 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/29 15:37:12 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dst, const char *src)
{
	size_t src_len = 0;
	while (src[src_len] != '\0')
	{
		dst[src_len] = src[src_len];
		src_len++;
	}
	dst[src_len] = '\0';
	return dst;
}
