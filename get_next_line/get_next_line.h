/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:23:46 by yakong            #+#    #+#             */
/*   Updated: 2026/10/20 16:23:01 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Function prototype
char	*get_next_line(int fd);

// String manipulating functions
int		ft_strlen(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif