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
	
	pen_colour(CYAN);
	turn(162);
	forward(200);
	turn(144);
	forward(200);
	turn(144);
	forward(200);
	turn(144);
	forward(200);
	turn(144);
	forward(200);
	pen_up();
	
	forward(50);
	
	pen_down();
	pen_colour(RED);
	forward(100);
	turn(144);
	forward(100);
	turn(144);
	forward(100);
	turn(144);
	forward(100);
	turn(144);
	forward(100);
	pen_up();
	
	forward(300);
	
	pen_down();
	pen_colour(YELLOW);
	forward(150);
	turn(144);
	forward(150);
	turn(144);
	forward(150);
	turn(144);
	forward(150);
	turn(144);
	forward(150);
	pen_up();
	
	turn(-15);
	forward(400);
	
	pen_down();
	pen_colour(BLACK);
	forward(250);
	turn(144);
	forward(250);
	turn(144);
	forward(250);
	turn(144);
	forward(250);
	turn(144);
	forward(250);
	pen_up();
	
	forward(300);
	turn(-25);
	
	pen_down();
	pen_colour(GREEN);
	forward(350);
	turn(144);
	forward(350);
	turn(144);
	forward(350);
	turn(144);
	forward(350);
	turn(144);
	forward(350);
	pen_up();
	
	hide_turtle();
	
	return(p1world_shutdown());
}