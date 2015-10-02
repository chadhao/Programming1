/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q08.c
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p1image.h"

int get_r()
{
	srand(clock());
	return rand()%1000;
}

void replace(int target, int fa, int fr, int fg, int fb, int ra, int rr, int rg, int rb)
{
	int byte_count = get_image_width(target) * get_image_height(target) * 4;
	unsigned char* bytes = get_pixel_bytes(target);
	
	for (int i = 0; i < byte_count; i += 4)
	{
		if (bytes[i] == fb && bytes[i+1] == fg && bytes[i+2] == fr && bytes[i+3] == fa)
		{
			bytes[i] = rb;
			bytes[i+1] = rg;
			bytes[i+2] = rr;
			bytes[i+3] = ra;
			/*
			//randam stars generating algorithm comments out due to low execution efficiency.
			if (get_r() < 2)
			{
				bytes[i] = 255;
				bytes[i+1] = 255;
				bytes[i+2] = 255;
				bytes[i+3] = 255;
			}
			*/
		}
	}
}

int main(int argc, char* argv[])
{
	create_image_world();
	
	int image = load_bmp("bigben.bmp");
	unsigned char* bytes = get_pixel_bytes(image);
	
	int b = bytes[0];
	int g = bytes[1];
	int r = bytes[2];
	int a = bytes[3];
	
	replace(image, a, r, g, b, 255, 0, 0, 0);
	
	put_image(image, get_screen_width()/2-get_image_width(image)/2, get_screen_height()/2-get_image_height(image)/2);
	
	return p1world_shutdown();
}