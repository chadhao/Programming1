/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab05ex05.c
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


int main(int argc, char* argv)
{
	turn_on_debug_output();
	create_image_world();
	
	// Write your code here
	int v = load_bmp("plane.bmp");
	put_image(v, (get_screen_width() / 2) - (get_image_width(v) / 2), (get_screen_height() / 2) - (get_image_height(v) / 2));
	
	return p1world_shutdown();

}