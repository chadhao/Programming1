/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	pen_colour(MAGENTA);
	forward(200);
	turn(120);
	
	pen_colour(CYAN);
	forward(200);
	turn(120);
	
	pen_colour(YELLOW);
	forward(200);
	turn(120);
	
	return (p1world_shutdown());
}