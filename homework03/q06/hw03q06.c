/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw03q06.c
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

#include "hw03q06.h"

void turn_right()
{
	turn_robot_left();
	turn_robot_left();
	turn_robot_left();
}

void turn_around()
{
	turn_robot_left();
	turn_robot_left();
}

void complete_maze()
{
	move_robot_forwards();
	
	while (!is_item_on_ground_at_robot())
	{
		if (is_space_in_front_of_robot_clear())
		{
			turn_robot_left();
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
			turn_robot_left();
			if (is_robot_facing_wall())
			{
				turn_around();
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
	}
}