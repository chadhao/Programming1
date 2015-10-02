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
	pen_colour(RED);
	turn(105);
	forward(200);
	
	turn(-120);
	forward(200);
	
	turn(-120);
	forward(400);
	
	turn(-120);
	forward(200);
	
	turn(-120);
	forward(200);
	
	turn(-30);
	forward(200);
	
	turn(LEFT);
	forward(200);
	
	turn(LEFT);
	forward(200);
	
	turn(LEFT);
	forward(400);
	
	turn(LEFT);
	forward(200);
	
	turn(LEFT);
	forward(200);
	
	pen_up();
	hide_turtle();
	
	return(p1world_shutdown());
}