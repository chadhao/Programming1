
#pragma once

#ifndef __P1IMAGE_H__
#define __P1IMAGE_H__

/* Framework Functions: */

void turn_on_debug_output();
    
void turn_off_debug_output();

void set_delay_time(int milliseconds);

void print_stub(char* pMessage);

int p1world_shutdown();

/* Utils */

int get_random(int low, int high);

void create_image_world();

int create_image(int width, int height);

int grab_image(int x, int y, int width, int height);

int load_bmp(char* filename);

int save_png(int handle, char* filename);

int get_image_width(int handle);

int get_image_height(int handle);

int get_screen_width();

int get_screen_height();

void put_image(int handle, int x, int y);

unsigned char* get_pixel_bytes(int image);

void free_image(int handle);

#endif /* __P1IMAGE_H__ */
