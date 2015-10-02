/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q02>.c
*  Author:     <Duan Hao>
*  Student Id: <1426688>
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
#include <stdio.h>
#include "p1student.h"


int get_random(int low, int high)
{
    int range = (high - low) + 1;
    
    int randomDelta = rand() % range;
    
    int randomNumber = randomDelta + low;
    
    return (randomNumber);
}

void draw_tree(int length)
{
	int random_angle = get_random(5, 35);
	float random_rate = get_random(14, 20) / 10.0;
	if (length >= 5)
	{
		forward(length);
		turn(-45+random_angle);
		draw_tree(length / random_rate);
		turn(90-random_angle);
		draw_tree(length / random_rate);
		turn(-45);
		forward(-length);
	}
}

int main(int argc, char* argv[])
{
	srand(clock());
	create_turtle_world();
	
	pen_up();
	forward(-150);
	pen_down();
	draw_tree(200);
	
	return p1world_shutdown();
}

