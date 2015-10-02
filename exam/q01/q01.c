
#include <p1student.h>


void draw_square()
{
	forward(100);
	turn(90);
	forward(100);
	turn(90);
	forward(100);
	turn(90);
	forward(100);
	turn(90);
}

void move_to_next()
{
	pen_up();
	turn(90);
	forward(200);
	turn(270);
	pen_down();
}

void draw_triangle()
{
	turn(30);
	forward(100);
	turn(120);
	forward(100);
	turn(120);
	forward(100);
	turn(90);
}

void draw_inverted_triangle()
{
	turn(-60);
	draw_triangle();
	turn(60);
}

int main(int argc, char* argv[])
{
	create_turtle_world();
	
	draw_square();
	move_to_next();
	draw_triangle();
	move_to_next();
	draw_inverted_triangle();
	
	return p1world_shutdown();
}
