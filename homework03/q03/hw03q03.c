/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw03q03.c
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

#include "p1student.h"

/*
1.check SW room.
2.if there is a beeper, pick it up and move to NW room.
3.if not, check NW room.
4.move across the corridor to check if there is wall.
5.if there is wall, move to the other room and drop the beeper.
6.if not, walk in and drop the beeper.
*/

void turn_around()
{
	turn_robot_left();
	turn_robot_left();
}

void turn_right()
{
	turn_robot_left();
	turn_robot_left();
	turn_robot_left();
}

void move_forward(int n)
{
	for (int i = 0; i < n; i++)
	{
		move_robot_forwards();
	}
}

void move_beeper()
{
	move_robot_forwards();
	turn_robot_left();
	move_forward(3);
	if (is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
		turn_around();
		move_forward(3);
		if (is_robot_facing_wall())
		{
			turn_robot_left();
			move_forward(4);
			turn_right();
			move_forward(3);
			drop_item_from_robot();
		}
		else
		{
			move_forward(3);
			drop_item_from_robot();
		}
	}
	else
	{
		turn_around();
		move_forward(3);
		turn_robot_left();
		move_forward(4);
		turn_robot_left();
		move_forward(3);
		pick_up_item_with_robot();
		turn_around();
		move_forward(3);
		if (is_robot_facing_wall())
		{
			turn_right();
			move_forward(4);
			turn_robot_left();
			move_forward(3);
			drop_item_from_robot();
		}
		else
		{
			move_forward(3);
			drop_item_from_robot();
		}
	}
}