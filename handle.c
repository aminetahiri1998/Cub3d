/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:36:16 by atahiri           #+#    #+#             */
/*   Updated: 2020/02/18 17:21:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int     check_folder(char *str)
// {
//     int     ret;
//     int     fd;
//     char    *buff;

//     fd = open(str, O_RDONLY);
//     if (fd < 0)
//         return (-1);
//     if (!(buff = malloc (sizeof(char) * 2)))
//         return (-1);
//     buff[1] = '\0';
//     ret = read(fd, buff, 1);
//     if (ret == -1)
//     {
//         if (buff != 0)
//             free(buff);
//         return(-1);
//     }
//     if (buff != 0)
//         free(buff);
//     return (0);
// }

int     handle_argv(char *str)
{
    int len;
    
    len = ft_strlen(str);
    //check_folder(str);
    if (ft_strncmp(str + (len - 4), ".cub", 4))
        return (2);
    return (0);
}

// int		handle(char *path, t_parse *parse, t_data *data)
// {
// 	char	*buffer;
// 	int		ret;
// 	int		fd;

// 	init_parse(parse);
// 	fd = open(path, O_RDONLY);
// 	set_num_line(data, path);
// 	buffer = NULL;
// 	if (!(data->map = malloc(sizeof(char *) * data->num_line + 1)))
// 	{
// 		write(2, "Error,\nMalloc failed.\n", 21);
// 		exit(0);
// 	}
// 	while ((ret = get_next_line(fd, &buffer)) > 0)
// 	{
// 		norme_main_parse2(buffer, parse, data);
// 		free(buffer);
// 	}
// 	if (ret == 0)
// 		free(buffer);
// 	check_char(data);
// 	return (0);
// }