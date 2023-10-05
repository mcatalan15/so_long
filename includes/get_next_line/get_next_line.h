/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:12:22 by mcatalan          #+#    #+#             */
/*   Updated: 2023/07/07 11:21:44 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>

// get_next_line.c
char	*get_next_line(int fd);
char	*readbuf(int fd, char *str);
char	*n_line(char *str);
char	*clean_storage(char *str);
char	*ft_free(char **str);

// get_next_line_utils.c
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strl(char *str);
char	*ft_strchr(const char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t l);
char	*ft_strncpy(char *dest, const char *src, size_t n);
#endif
