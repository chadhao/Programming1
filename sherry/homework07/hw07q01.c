/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q01>.c
*  Author:     <Sherry Hong>
*  Student Id: <14874433>
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

void draw_sides(int how_many, int length, int angle)
{
	if(how_many > 0)
	{
		forward(length);
		turn(angle);
		draw_sides(how_many - 1, length, angle);
	}
}

void draw_box(int size)
{
	draw_sides(4, size, 90);
}

void draw_fractal(int size_from, int size_to)
{
	if (size_from >= size_to)
	{
		draw_box(size_from);
		forward(size_from);
		draw_fractal(size_from / 2, size_to);
		turn(RIGHT);
		forward(size_from);
		draw_fractal(size_from / 2, size_to);
		turn(RIGHT);
		forward(size_from);
		turn(RIGHT);
		forward(size_from);
		turn(RIGHT);
	}
}

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	pen_up();
	forward(-300);
	pen_down();
	
	draw_fractal(256, 8);
		
	return p1world_shutdown();
}

