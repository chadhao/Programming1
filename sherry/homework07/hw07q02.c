/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q02>.c
*  Author:     <Sherry Hong>
*  Student Id: <14874433>
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/

#include <time.h>
#include <stdlib.h>
#include "p1student.h"


int get_random(int low, int high)
{
    int range = (high - low) + 1;
    
    int randomDelta = rand() % range;
    
    int randomNumber = randomDelta + low;
    
    return (randomNumber);
}

void draw_tree(int size_from, int size_to)
{
	if (size_from >= size_to)
	{
		forward(size_from);
		turn(-45);
		draw_tree(size_from / 2, size_to);
		turn(RIGHT);
		draw_tree(size_from / 2, size_to);
		turn(-45);
		forward(-size_from);
	}
}

int main(int argc, char* argv[])
{
	srand(time(0));
	create_turtle_world();
	
	pen_up();
	forward(-150);
	pen_down();
	draw_tree(300, 5);
	
	return p1world_shutdown();
}

