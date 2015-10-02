/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw07q01.c
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

void draw_fractal(int length)
{
	if (length >= 8)
	{
		draw_box(length);
		forward(length);
		draw_fractal(length / 2);
		turn(90);
		forward(length);
		draw_fractal(length / 2);
		turn(90);
		forward(length);
		turn(90);
		forward(length);
		turn(90);
	}
}

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	pen_up();
	forward(-300);
	turn(-90);
	forward(500);
	turn(90);
	pen_down();
	
	draw_fractal(256);
		
	return p1world_shutdown();
}

