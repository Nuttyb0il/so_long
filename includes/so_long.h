/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/22 11:58:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/lists.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define CHARSET "01CEP\n"

// error section
# define INVALID_COLLECTIBLES -32767
# define INVALID_SPAWNS -32773
# define INVALID_EXITS -32769
# define INVALID_MAP_CHARACTERS -32770
# define INVALID_LINE_LENGTH -32771
# define MAP_NOT_CLOSED -32772

typedef struct s_map
{
	char		*map;
	char		*path;
	t_chain_lst *lines;
	int			length;
	int			height;
	int			width;
	int			sanity;
	int			fd;
	int			collectibles;
	int			spawns;
	int			exits;
}	t_map;

t_map	ft_load_map(char *path);
void	clean_exit(int code);
int		ft_valid_line_length(t_chain_lst *lines, int expected);
int		ft_map_closed(t_chain_lst *lines);
int		ft_valid_charset(char *s);
void	ft_print_markdown(int code, t_map *map);
int		ft_is_valid_char(char c);
int		ft_is_ber(char *path);
#endif