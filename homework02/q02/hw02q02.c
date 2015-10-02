/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q02.c
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

void next()
{
	pen_up();
	forward(55);
	pen_down();
}

int main(int argc, char* argv[])
{
	create_turtle_world();
	turn_on_debug_output();
	
	pen_down();
	print_stub("Drawing a Triangle");
	
	for(int n = 0; n < 3; n++)
	{
		forward(25);
		turn(120);
	}
	
	next();
	print_stub("Drawing a Square");
	
	for(int n = 0; n < 4; n++)
	{
		forward(25);
		turn(90);
	}
	
	next();
	print_stub("Drawing a Pentagon");
	
	for(int n = 0; n < 5; n++)
	{
		forward(25);
		turn(72);
	}
	
	next();
	print_stub("Drawing a Hexagon");
	
	for(int n = 0; n < 6; n++)
	{
		forward(25);
		turn(60);
	}
	
	return(p1world_shutdown());
}