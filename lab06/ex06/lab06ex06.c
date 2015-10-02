/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex06.c
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

#include "lab06ex06.h"

void turn_right()
{
	turn_robot_left();
	turn_robot_left();
	turn_robot_left();
}

void escape_room()
{
	/*
	//This is the Left-hand algorithm.
	turn_robot_left();
	while (!is_item_on_ground_at_robot())
	{
		turn_robot_left();
		if (is_robot_facing_wall())
		{
			turn_right();
			if (is_robot_facing_wall())
			{
				turn_right();
				move_robot_forwards();
			}
			else
			{
				move_robot_forwards();
			}
		}
		else
		{
			move_robot_forwards();
		}
	}
	*/
	
	while (!is_item_on_ground_at_robot())
	{
		while (!is_robot_facing_wall())
		{
			move_robot_forwards();
		}
		turn_right();
		if (is_robot_facing_wall())
		{
			turn_robot_left();
			turn_robot_left();
		}
	}
}