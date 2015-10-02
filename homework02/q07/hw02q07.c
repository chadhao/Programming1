/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q07.c
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

#include "p1student.h"

// use colour, functions with input parameters, loops

//This function is used to draw different size of triangles in different colours.
void draw_triangle(int scale)
{
	pen_colour(NEXT);
	pen_down();
	forward(10 * scale);
	turn(105);
	forward(5 * scale);
	turn(105);
	forward(10 * scale);
	turn(180);
	pen_up();
}

int main(int argc, char* argv[])
{
	set_delay_time(1);
	create_turtle_world();
	
	for (int n = 1; n < 73; n++)
	{
		draw_triangle(n);
	}
	
	return(p1world_shutdown());
}