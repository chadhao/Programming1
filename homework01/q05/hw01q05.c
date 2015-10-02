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

void draw_0()
{
	pen_down();
	forward(200);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	pen_up();
}

void draw_1()
{
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	pen_down();
	forward(200);
	pen_up();
	forward(-200);
	turn(LEFT);
	forward(100);
	turn(RIGHT);
}

void draw_2()
{
	forward(200);
	turn(RIGHT);
	pen_down();
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	pen_up();
	forward(-100);
	turn(LEFT);
}

void draw_3()
{
	turn(RIGHT);
	pen_down();
	forward(100);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	forward(-100);
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(100);
	pen_up();
	turn(RIGHT);
	forward(-200);
}

void draw_4()
{
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	pen_down();
	forward(200);
	forward(-100);
	turn(LEFT);
	forward(100);
	turn(RIGHT);
	forward(100);
	pen_up();
	forward(-200);
}

void draw_5()
{
	pen_down();
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	pen_up();
	forward(-100);
	turn(LEFT);
	forward(-200);
}

void draw_6()
{
	pen_down();
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	forward(-100);
	turn(LEFT);
	forward(-200);
	pen_up();
}

void draw_7()
{
	forward(200);
	turn(RIGHT);
	pen_down();
	forward(100);
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
	pen_up();
	forward(100);
	turn(RIGHT);
}

void draw_8()
{
	pen_down();
	forward(200);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	turn(RIGHT);
	forward(100);
	forward(-100);
	turn(LEFT);
	forward(-100);
	pen_up();
}

void draw_9()
{
	turn(RIGHT);
	forward(100);
	turn(LEFT);
	pen_down();
	forward(200);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	turn(LEFT);
	forward(100);
	pen_up();
	forward(-100);
	turn(LEFT);
	forward(-100);
}

void draw_space()
{
	turn(RIGHT);
	forward(150);
	turn(LEFT);
}

void draw_my_student_id()
{
	draw_1();
	draw_space();
	draw_4();
	draw_space();
	draw_2();
	draw_space();
	draw_6();
	draw_space();
	draw_6();
	draw_space();
	draw_8();
	draw_space();
	draw_8();
}

int main(int argc, char* argv[])
{
	set_delay_time(1);
	create_turtle_world();
	
	pen_up();
	pen_colour(BLACK);
	turn(LEFT);
	forward(550);
	turn(RIGHT);
	
	draw_my_student_id();
	
	hide_turtle();
	return(p1world_shutdown());
}