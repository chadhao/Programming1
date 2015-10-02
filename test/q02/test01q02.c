/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  IMPORTANT: REMEMBER TO sync BEFORE YOU LEAVE THE EXAM ROOM
*
*******************************************************************************/

#include "p1student.h"

// This is the function to draw one triangle.
void draw_triangle()
{
	forward(100);
	turn(120);
	forward(100);
	turn(120);
	forward(100);
}


int main(int argc, char* argv[])
{
	create_turtle_world();
	
	// Add your code here
	draw_triangle();
	turn(-60);
	draw_triangle();
		
	return p1world_shutdown();
}