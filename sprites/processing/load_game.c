/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:00:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/01/31 15:57:17 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game ft_load_game(char **sprites_path, char **sprites_name, char *map_path, int sprite_count)
{
    t_game game;
    int i;

    ft_init_game(&game, sprite_count);
    i = 0;
    while (i < sprite_count)
    {
        ft_decode_sprite(sprites_name[i], sprites_path[i], &game.sprites[i]);
        if (ft_strncmp(sprites_name[i], "mad", 3) == 0)
            ft_random_hair(&game.sprites[i]);
        free(sprites_path[i]);
        free(sprites_name[i]);
        i++;
    }
    free(sprites_path);
    free(sprites_name);
    ft_buffer_map(map_path, game.map);
    return (game);
}

void ft_init_game(t_game *game, int sprite_count)
{
    int i;

    i = 0;
    game->sprites = (t_sprite*) malloc(sizeof(t_sprite) * sprite_count);
    game->map = (t_map*) malloc(sizeof(t_map));
    game->map->map_string = NULL;
    game->sprite_count = sprite_count;
    game->mlx_ptr = NULL;
    while (i < sprite_count)
    {
        game->sprites[i].name = NULL;
        game->sprites[i].width = 0;
        game->sprites[i].height = 0;
        game->sprites[i].compressed = 0;
        game->sprites[i].palette = ft_new_palette();
        game->sprites[i].pixels = NULL;
        i++;
    }
}