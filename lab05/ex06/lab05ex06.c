/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab05ex06.c
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


void blue_fill(int image)
{
	unsigned char* bytes = get_pixel_bytes(image);
	int byte_count = get_image_height(image) * get_image_width(image) * 4;
	for(int i = 0; i < byte_count; i += 4)
	{
		// Set pixel element here to fill image with a blue colour
		// Remember that bytes can only contain values in the range 0 - 255
		// Or 0x00 to 0xff if you prefer
		bytes[i] = 255;
	}
}

void fill(int image_width, int image_height, int image_position_x, int image_position_y, int a, int r, int g, int b)
{
	int image = create_image(image_width, image_height);
	unsigned char* bytes = get_pixel_bytes(image);
	int byte_count = get_image_height(image) * get_image_width(image) * 4;
	for(int i = 0; i < byte_count; i += 4)
	{
		bytes[i] = b;
	}
	for(int i = 1; i < byte_count; i += 4)
	{
		bytes[i] = g;
	}
	for(int i = 2; i < byte_count; i += 4)
	{
		bytes[i] = r;
	}
	for(int i = 3; i < byte_count; i += 4)
	{
		bytes[i] = a;
	}
	put_image(image, image_position_x, image_position_y);
}

int main(int argc, char* argv)
{
	turn_on_debug_output();
	create_image_world();
	
	// Write your code here
	int image = create_image(100, 100);
	
	blue_fill(image);

	put_image(image, (get_screen_width() / 2) - 50, (get_screen_height() / 2) - 50);

	// Add your own experiments here!
	fill(200, 200, 0, 0, 125, 255, 0, 0);
	fill(150, 150, 250, 0, 255, 0, 255, 0);
	fill(50, 300, 350, 450, 255, 123, 12, 1);
	fill(550, 150, 650, 300, 255, 26, 82, 36);
	
	return p1world_shutdown();

}