/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:02 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/04 12:12:34 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_input(int keysym, mlx_data *data)
{
	printf("The key %d was pressed\n", keysym);
	if (keysym == 53) // Replace 53 with KEY_ESC constant if you defined it
	{
		printf("Esc pressed\n");
		kill_game_free(data->mlx, data->window);
		exit(0); // Exit cleanly with 0
	}
	else if (keysym == 13) // move w
		data ->player.pos_y -= 10;
	else if (keysym == 0) // move a
		data ->player.pos_x -= 10;
	else if (keysym == 1) // move down
		data->player.pos_y += 10;
	else if (keysym == 2)
		data->player.pos_x += 10;
	mlx_clear_window(data ->mlx, data-> window);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> bg_img.img, data -> bg_img.pos_x, data -> bg_img.pos_y);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> player.img, data -> player.pos_x, data -> player.pos_y);
	return (0);
}