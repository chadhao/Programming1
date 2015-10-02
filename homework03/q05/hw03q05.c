/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw03q05.c
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
********************************************************************************/

#include <stdlib.h>

#include "hw03q05.h"

int get_random(int low, int high)
{
	return low + (rand() % (1 + high - low));
}

void turn_right()
{
	turn_robot_left();
	turn_robot_left();
	turn_robot_left();
}

void setup_maze()
{
	int e = 0;
	for (int y = 1; y < 10; y += 2)
	{
		e = get_random(0, 9);
		for (int x = 0; x < 10; x++)
		{
			if (x != e)
			{
				setup_wall(x, y);
			}
		}
	}
}

void back()
{
	turn_robot_left();
	while (is_space_in_front_of_robot_clear())
	{
		move_robot_forwards();
	}
	turn_right();
}

void complete_maze()
{
	turn_robot_left();
	for (int i = 0; i < 5; i++)
	{
		back();
		while (is_robot_facing_wall())
		{
			turn_right();
			move_robot_forwards();
			turn_robot_left();
		}
		move_robot_forwards();
		move_robot_forwards();
	}
}