/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex03.c
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
*******************************************************************************/

#include "p1student.h"

void draw_flag()
{
	forward(300);
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(200);
}

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	draw_flag();
	
	return(p1world_shutdown());
}