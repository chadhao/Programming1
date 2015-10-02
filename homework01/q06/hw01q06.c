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

void draw_my_name()
{
	pen_colour(BLACK);
	pen_down();
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(200);
	turn(LEFT);
	forward(100);
	pen_up();
	forward(-50);
	turn(LEFT);
	pen_down();
	forward(200);
	pen_up();
	
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(180);
	
	pen_down();
	forward(100);
	turn(LEFT);
	forward(50);
	turn(LEFT);
	forward(100);
	pen_up();
	
	turn(RIGHT);
	forward(50);
	
	pen_down();
	forward(50);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(180);
	
	pen_down();
	forward(100);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(100);
	pen_up();
}

int main(int argc, char* argv[])
{
	set_delay_time(1);
	create_turtle_world();
	
	pen_up();
	turn(LEFT);
	forward(200);
	turn(RIGHT);
	
	draw_my_name();
	
	hide_turtle();
	return(p1world_shutdown());
}