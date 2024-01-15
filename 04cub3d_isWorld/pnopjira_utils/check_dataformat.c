/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dataformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:59:07 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/13 20:56:13 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_content(t_list **iden, char **dst, char **src, char *key)
{
	char	*str;

	str = ft_strtrim(*src, key);
	*dst = ft_strtrim(str, " ");
	free(str);
	if (!ft_strncmp(key, "NO", 2) || !ft_strncmp(key, "SO", 2) || \
	!ft_strncmp(key, "WE", 2) || !ft_strncmp(key, "EA", 2))
	{
		if (invalid_filepath(*dst, "./textures/", ".xpm"))
			return (free(*src), EXIT_FAILURE);
	}
	else if (!ft_strncmp(key, "F", 1) || !ft_strncmp(key, "C", 1))
	{
		if (invalid_color_code(*dst))
			return (free(*src), EXIT_FAILURE);
	}
	key_to_content((void **)iden, key, *dst);
	free(*src);
	return (EXIT_SUCCESS);
}

int	ck_no_so_we_ea(char *tmp, t_list **iden)
{
	char	*str1;
	char	*str2;

	str1 = NULL;
	str2 = (char *) malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str2, tmp, ft_strlen(tmp) - 1);
	if (ft_strncmp(str2, "NO ", 3) == 0)
		if (init_content(iden, &str1, &str2, "NO"))
			return (free(str1), 3);
	if (ft_strncmp(str2, "SO ", 3) == 0)
		if (init_content(iden, &str1, &str2, "SO"))
			return (free(str1), 3);
	if (ft_strncmp(str2, "WE ", 3) == 0)
		if (init_content(iden, &str1, &str2, "WE"))
			return (free(str1), 3);
	if (ft_strncmp(str2, "EA ", 3) == 0)
		if (init_content(iden, &str1, &str2, "EA"))
			return (free(str1), 3);
	return (EXIT_SUCCESS);
}

int	ck_f_c_color(char *tmp, t_list **iden)
{
	char	*str1;
	char	*str2;

	str1 = NULL;
	str2 = (char *)malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str2, tmp, ft_strlen(tmp) - 1);
	if (ft_strncmp(str2, "F ", 2) == 0)
		if (init_content(iden, &str1, &str2, "F"))
			return (free(str1), 6);
	if (ft_strncmp(str2, "C ", 2) == 0)
		if (init_content(iden, &str1, &str2, "C"))
			return (free(str1), 6);
	return (EXIT_SUCCESS);
}

void	ck_data_format(char *tmp, int *err, t_map **map)
{
	if (tmp[0] == '\n' && tmp[1] == '\0')
	{
		if ((*map)->map_begin == 1)
			*err = 5;
		else
			*err = 0;
	}
	else if (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "SO ", 3) \
	|| !ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "EA ", 3))
		*err = ck_no_so_we_ea(tmp, &(*map)->iden);
	else if (!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "C ", 2))
		*err = ck_f_c_color(tmp, &(*map)->iden);
	else if (ft_strncmp(tmp, "1", 1) == 0 || ft_strncmp(tmp, "0", 1) == 0)
		*err = ck_map_info(map);
	else
		*err = -1;
}

void	ck_invalid_data(int *err, int fd1, t_map **map)
{
	char	*line;
	char	*tmp;
	
	line = get_next_line(fd1);
	while (line)
	{
		if (before_map(map, err))
			break ;
		tmp = ft_strtrim(line, " ");
		free(line);
		line = NULL;
		ck_data_format(tmp, err, map);
		free(tmp);
		if (*err != 0)
			break ;
		line = get_next_line(fd1);
	}
	if (line)
		free(line);
	close(fd1);
}