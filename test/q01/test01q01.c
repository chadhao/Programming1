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

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	// Add your code here
	pen_colour(GREEN);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);	
	
		
	return p1world_shutdown();
}