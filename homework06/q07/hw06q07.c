/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q07.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://www.johndcook.com/blog/2009/08/24/algorithms-convert0color-grayscale/
********************************************************************************/

#include "p1image.h"

int to_greyscale(int source)
{
	int image_grey = create_image(get_image_width(source), get_image_height(source));
	int byte_count = get_image_width(source) * get_image_height(source) * 4;
	unsigned char* bytes = get_pixel_bytes(source);
	unsigned char* bytes_grey = get_pixel_bytes(image_grey);
	
	for (int i = 0; i < byte_count; i += 4)
	{
		//calculate the average value of R/G/B and give the value to the new image bytes
		int value = (bytes[i] + bytes[i+1] + bytes[i+2]) / 3;
		bytes_grey[i] = value;
		bytes_grey[i+1] = value;
		bytes_grey[i+2] = value;
	}
	return image_grey;
}

int main(int argc, char* argv[])
{
	create_image_world();
	
	int image = load_bmp("boats.bmp");
	
	put_image(to_greyscale(image), get_screen_width()/2-get_image_width(image)/2, get_screen_height()/2-get_image_height(image)/2);
	
	return p1world_shutdown();
}