/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:43:02 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 09:43:25 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX	5
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_token
{
	char			buff[BUFFER_SIZE];
	struct s_token	*next;
	size_t			nbyte;
}				t_token;

typedef struct s_vars
{
	int		fd;
	int		eof;
	int		fin;
	t_token	*t;
	t_token	*t_last;
	size_t	offset;
	size_t	nl_bytes;
	size_t	tok_len;
}				t_vars;

char	*get_next_line(int fd);
void	consume_token(t_vars *v, char *str);
void	get_nlbyte(t_vars *v);
void	read_next(t_vars *v);
#endif