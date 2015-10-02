
#include <p1student.h>



int main(int argc, char* argv[])
{
	create_turtle_world();
	turn(90);
	for (int i = 0; i < 7; i++)
	{
		forward(20);
		pen_up();
		if (i < 6)
		{
			forward(20);
		}
		pen_down();
	}
	hide_turtle();
	return p1world_shutdown();
}
