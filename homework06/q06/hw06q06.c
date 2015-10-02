/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q06.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/

#include "p1image.h"
#include <stdlib.h>
#include <time.h>

int get_random_position(int screen_high, int image_high)
{
	srand(clock());
	int r = rand() % screen_high;
	
	if (r > image_high)
	{
		r = r - image_high;
	}
	
	return r;
}

int main(int argc, char* argv[])
{
	int image;
	int image_small;
	
	create_image_world();
	
	image = load_bmp("meerkat.bmp");
	image_small = create_image(230, 150);
	
	unsigned char* image_bytes = get_pixel_bytes(image);
	unsigned char* image_small_bytes = get_pixel_bytes(image_small);
	int i = 0;
	
	for (int y = 0; y < 150; y++)
	{
		for (int x = 0; x < 230; x++)
		{
			int j = ((y+(get_image_height(image)/5-50)) * get_image_width(image) + (x+(get_image_width(image)/3-50))) * 4;
			image_small_bytes[i] = image_bytes[j];
			image_small_bytes[i+1] = image_bytes[j+1];
			image_small_bytes[i+2] = image_bytes[j+2];
			image_small_bytes[i+3] = image_bytes[j+3];
			i += 4;
		}
	}
	
	free_image(image);
	
	for (int k = 0; k < 30; k++)
	{
		put_image(image_small, get_random_position(get_screen_width(), get_image_width(image_small)), get_random_position(get_screen_height(), get_image_height(image_small)));
	}
	
	return p1world_shutdown();
}