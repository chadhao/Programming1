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

void draw_walls()
{
	print_stub("draw walls");
	pen_colour(BLACK);
	pen_down();
	forward(600);
	turn(RIGHT);
	forward(800);
	turn(RIGHT);
	forward(600);
	turn(RIGHT);
	forward(800);
	turn(RIGHT);
	pen_up();
}

void draw_window()
{
	print_stub("draw window");
	pen_colour(BLUE);
	pen_down();
	forward(150);
	turn(RIGHT);
	forward(150);
	turn(RIGHT);
	forward(150);
	turn(RIGHT);
	forward(150);
	turn(RIGHT);
	forward(75);
	turn(RIGHT);
	forward(150);
	turn(LEFT);
	forward(75);
	turn(LEFT);
	forward(75);
	turn(LEFT);
	forward(150);
	turn(RIGHT);
	forward(75);
	turn(RIGHT);
	pen_up();
}

void draw_door()
{
	print_stub("draw door");
	pen_colour(WHITE);
	pen_down();
	forward(300);
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
	forward(300);
	pen_up();
	turn(RIGHT);
	forward(200);
	turn(RIGHT);
}

void draw_roof()
{
	print_stub("roof");
	pen_colour(RED);
	forward(300);
	pen_down();
	turn(-127);
	forward(700);
	forward(-700);
	turn(-106);
	forward(700);
	forward(-700);
	turn(-127);
	pen_up();
	forward(-300);
}

void draw_garden_element()
{
	forward(50);
	turn(-120);
	forward(50);
	turn(120);
}

void draw_garden()
{
	print_stub("draw garden");
	pen_colour(GREEN);
	pen_down();
	turn(150);
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	draw_garden_element();
	turn(120);
	pen_up();
	forward(1200);
	turn(RIGHT);
}

void draw_sky_element()
{
	pen_colour(RED);
	forward(50);
	turn(-120);
	pen_colour(YELLOW);
	forward(50);
	turn(-120);
	forward(50);
	turn(-120);
	pen_colour(RED);
	forward(50);
}

void draw_sky()
{
	print_stub("draw sky");
	pen_down();
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	draw_sky_element();
	turn(45);
	pen_up();
}

int main(int argc, char* argv[])
{
	turn_on_debug_output();
	set_delay_time(1);
	create_turtle_world();
	
	pen_up();
	turn(LEFT);
	forward(400);
	turn(RIGHT);
	forward(-400);
	
	draw_walls();
	
	forward(600);
	turn(RIGHT);
	forward(400);
	turn(LEFT);
	
	draw_roof();
	
	forward(-225);
	turn(LEFT);
	forward(325);
	turn(RIGHT);
	
	draw_window();
	
	turn(RIGHT);
	forward(500);
	turn(LEFT);
	
	draw_window();
	
	forward(-375);
	turn(LEFT);
	forward(275);
	turn(RIGHT);
	
	draw_door();
	
	turn(LEFT);
	forward(500);
	turn(RIGHT);
	
	draw_garden();
	
	forward(750);
	
	draw_sky();
	
	hide_turtle();
	turn_off_debug_output();
	return(p1world_shutdown());
}