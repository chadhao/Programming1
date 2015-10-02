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
	
	pen_up();
	forward(200);
	turn(LEFT);
	forward(400);
	turn(LEFT);
	forward(100);
	turn(180);
	
	pen_down();
	pen_colour(BLACK);
	forward(100);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(100);
	forward(-50);
	turn(RIGHT);
	forward(50);
	forward(-50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	pen_up();
	
	forward(25);
	pen_down();
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(50);
	turn(LEFT);
	forward(100);
	turn(RIGHT);
	pen_up();
	
	forward(25);
	pen_down();
	forward(100);
	forward(-50);
	turn(RIGHT);
	forward(100);
	pen_up();
	
	forward(50);
	turn(RIGHT);
	forward(200);
	
	pen_down();
	pen_colour(MAGENTA);
	turn(LEFT);
	forward(100);
	forward(-100);
	turn(LEFT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(-135);
	forward(70);
	pen_up();
	
	forward(-70);
	turn(-45);
	forward(75);
	
	pen_down();
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(25);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(75);
	turn(LEFT);
	forward(25);
	turn(LEFT);
	
	pen_down();
	forward(50);
	turn(LEFT);
	forward(25);
	turn(LEFT);
	forward(50);
	turn(RIGHT);
	forward(25);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(-75);
	turn(LEFT);
	forward(50);
	turn(180);
	
	pen_down();
	forward(100);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(75);
	turn(RIGHT);
	
	pen_down();
	forward(100);
	turn(LEFT);
	forward(50);
	turn(LEFT);
	forward(50);
	turn(LEFT);
	forward(50);
	pen_up();
	
	forward(-125);
	turn(LEFT);
	forward(50);
	turn(RIGHT);
	
	pen_down();
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(25);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(-75);
	turn(LEFT);
	forward(25);
	turn(180);
	
	pen_down();
	forward(50);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(25);
	turn(RIGHT);
	forward(50);
	turn(180);
	
	pen_down();
	forward(50);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(25);
	turn(RIGHT);
	
	pen_down();
	forward(50);
	turn(LEFT);
	forward(50);
	turn(LEFT);
	forward(50);
	forward(-100);
	turn(LEFT);
	forward(50);
	pen_up();
	
	forward(-150);
	turn(RIGHT);
	forward(50);
	
	pen_down();
	pen_colour(GREEN);
	forward(100);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	turn(RIGHT);
	forward(50);
	pen_up();
	
	forward(-75);
	turn(LEFT);
	
	pen_down();
	forward(50);
	pen_up();
	turn(180);
	forward(70);
	pen_down();
	forward(10);
	pen_up();
	
	hide_turtle();
	
	return (p1world_shutdown());
}