/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q05.c
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
#include <stdio.h>

int convertion(int width, int x, int y)
{
	return (y * width + x) * 4;
}

void set_pixel(int target, int x, int y, int a, int r, int g, int b)
{
	unsigned char* bytes = get_pixel_bytes(target);
	int starting_byte = convertion(get_image_width(target), x, y);
	bytes[starting_byte+0] = b;
	bytes[starting_byte+1] = g;
	bytes[starting_byte+2] = r;
	bytes[starting_byte+3] = a;
}

int main(int argc, char* argv[])
{
	create_image_world();
	
	int image = create_image(100, 100);
	
	for(int x = 0; x < 100; x++)
	{
		for(int y = 0; y < 100; y++)
		{
			if (x == y)
			{
				set_pixel(image, x, y, 255, 0, 0, 255);
			}
			else if (x+y == 100)
			{
				set_pixel(image, x, y, 255, 255, 0, 0);
			}
			else
			{
				set_pixel(image, x, y, 255, 0, 255, 0);
			}
		}
	}
	
	put_image(image, get_screen_width()/2-get_image_width(image)/2, get_screen_height()/2-get_image_height(image)/2);
	
	return p1world_shutdown();	
}