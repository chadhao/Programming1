/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q09.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://
********************************************************************************/
#include <math.h>
#include "p1image.h"

void replace(int target, int fa, int fr, int fg, int fb, int ra, int rr, int rg, int rb, float tolerance)
{
	int byte_count = get_image_width(target) * get_image_height(target) * 4;
	unsigned char* bytes = get_pixel_bytes(target);
	double colour;
	
	for (int i = 0; i < byte_count; i += 4)
	{
		colour = sqrt((bytes[i]-fb)*(bytes[i]-fb) + (bytes[i+1]-fg)*(bytes[i+1]-fg) + (bytes[i+2]-fr)*(bytes[i+2]-fr));
		if (colour < tolerance)
		{
			bytes[i] = rb;
			bytes[i+1] = rg;
			bytes[i+2] = rr;
			bytes[i+3] = ra;
		}
	}
}

int main(int argc, char* argv[])
{
	create_image_world();
	
	int image = load_bmp("rabbit.bmp");
	
	replace(image, 255, 255, 0, 0, 255, 0, 0, 0, 160);
	
	put_image(image, get_screen_width()/2-get_image_width(image)/2, get_screen_height()/2-get_image_height(image)/2);
	
	return p1world_shutdown();
}