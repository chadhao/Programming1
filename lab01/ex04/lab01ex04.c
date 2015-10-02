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

int main(int argc, char *argv[])
{
	create_turtle_world();
	
	forward(100);
	turn(90);
	
	forward(100);
	turn(90);
	
	forward(100);
	turn(90);
	
	forward(100);
	turn(90);
	turn(90);
	
	pen_colour(RED);
	forward(75);
	turn(90);
	
	forward(75);
	turn(90);
	
	forward(75);
	turn(90);
	
	forward(75);
	turn(90);
	turn(90);
	
	pen_colour(CYAN);
	forward(50);
	turn(90);
	
	forward(50);
	turn(90);
	
	forward(50);
	turn(90);
	
	forward(50);
	turn(90);
	turn(90);
	
	pen_colour(YELLOW);
	forward(25);
	turn(90);
	
	forward(25);
	turn(90);
	
	forward(25);
	turn(90);
	
	forward(25);
	hide_turtle();
	
	return(p1world_shutdown());
}
