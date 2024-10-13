#ifndef MAC_OS
#define MAC_OS 1
#endif

#if MAC_OS
#include "minilibx-macos/mlx.h"
#else
#include "minilibx-linux/mlx.h"
#endif

#include <stdio.h>
#include <stdlib.h>

void *mlx_ptr;
void *win_ptr;
void *background_ptr;
void *logo_ptr;
int color = 0x7F7F7F;

const int window_width = 500;
const int window_height = 375;

int key_press(int keycode, void *param)
{
    char str[24];
    sprintf(str, "Signal: %d", keycode);
    mlx_clear_window(mlx_ptr, win_ptr);
    mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, logo_ptr, 20, 10);
    mlx_string_put(mlx_ptr, win_ptr, (window_width / 2) - 40, window_height / 2, color, str);
    return (0);
}

int close_window(void *param)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
    exit(0);
}

int main()
{
    int img_width, img_height;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (perror("Error"), 1);
    win_ptr = mlx_new_window(mlx_ptr, window_width, window_height, "Signal Window");
    if (!win_ptr)
        return (perror("Error"), 1);
    background_ptr = mlx_xpm_file_to_image(mlx_ptr, "./xpm/background.xpm", &img_width, &img_height);
    logo_ptr = mlx_xpm_file_to_image(mlx_ptr, "./xpm/logo.xpm", &img_width, &img_height);

    mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, logo_ptr, 20, 10);
    mlx_key_hook(win_ptr, key_press, mlx_ptr);
    mlx_hook(win_ptr, 17, 1L << 17, close_window, mlx_ptr);

    mlx_loop(mlx_ptr);
    return (0);
}
