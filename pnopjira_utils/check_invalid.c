/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:00:23 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/01 13:27:45 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	explicit_error(int stage)
{
	if (stage != 0)
		perror(RED"Error\n"RESET);
	if (stage == 1)
		ft_putstr_fd(RED":empty file\n"RESET, 2);
	else if (stage == 2)
		ft_putstr_fd(RED":the type identity is invalid or lost\n"RESET, 2);
	else if (stage == 3)
		ft_putstr_fd(RED":type identity's file path is invalid\n"RESET, 2);
	else if (stage == 4)
		ft_putstr_fd(RED":the map is too big or too small\n"RESET, 2);
	else if (stage == 5)
		ft_putstr_fd(RED":the map is invalid\n"RESET, 2);
	else if (stage == 6)
		ft_putstr_fd(RED":color code is invalid\n"RESET, 2);
	else if (stage != 0)
		ft_putstr_fd(RED":unindentify\n"RESET, 2);
	return (stage);
}

int	invalid_filepath(char *maps_path, char *path, char *format)
{
	char	*begin;
	char	*end;
	int		len;
	int		fd;

	begin = maps_path;
	len = ft_strlen(maps_path);
	end = maps_path + (len - 4);
	if (len == 0)
		return (perror(RED"Error\n: Invalid Argument"RESET), 1);
	else if (ft_strncmp(begin, path, 5) != 0)
		return (perror(RED"Error\n: Invalid file path "RESET), 1);
	else if (ft_strncmp(end, format, 4) != 0)
		return (perror(RED"Error\n: Invalid file format "RESET), 1);
	fd = open(maps_path, O_RDONLY);
	if (fd == -1)
		return (perror(RED"Error\n: Invalid file name "RESET), 1);
	else
		close(fd);
	return (0);
}

int	invalid_color_code(char *rgb)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(rgb, ',');
	if (!color)
		return (EXIT_FAILURE);
	while (color[i])
		i++;
	if (i != 3)
		return (EXIT_FAILURE);
	else if (ft_strlen(rgb) < 5)
		return (EXIT_FAILURE);
	else if (ft_atoi(color[0]) > 255 || ft_atoi(color[0]) < 0)
		return (EXIT_FAILURE);
	else if (ft_atoi(color[1]) > 255 || ft_atoi(color[1]) < 0)
		return (EXIT_FAILURE);
	else if (ft_atoi(color[2]) > 255 || ft_atoi(color[2]) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ck_identify(int *err, t_list *iden)
{
	t_list	*temp;

	temp = iden;
	while (temp)
	{
		if (ft_strlen(temp->content) == 0)
		{
			*err = 2;
			return (EXIT_FAILURE);
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

int before_map(t_map **map, int *err)
{
	if ((*map)->map_begin == true)
	{
		if (ck_identify(err, (*map)->iden))
			return (EXIT_FAILURE);
	}
	else
		++(*map)->line_map_begin;
	return (EXIT_SUCCESS);
}