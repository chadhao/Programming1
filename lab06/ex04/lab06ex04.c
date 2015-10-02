/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex04.c
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
	turn(RIGHT);
	pen_up();
	forward(-200);
	pen_down();
}

void draw_n_flags(int n)
{
	for (int i = 0; i < n; i++)
	{
		draw_flag();
		turn(360 / n);
	}
}

int main(int agrc, char* argv[])
{
	create_turtle_world();
	
	draw_n_flags(91);
	
	return(p1world_shutdown());
}