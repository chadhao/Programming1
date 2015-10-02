/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex05.c
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

#include "lab06ex05.h"

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

void find_beepers()
{
	move_robot_forwards();
	if (!is_item_on_ground_at_robot())
	{
		turn_around();
		move_robot_forwards();
		turn_right();
		move_robot_forwards();
		if (!is_item_on_ground_at_robot())
		{
			turn_around();
			move_robot_forwards();
			turn_robot_left();
		}
	}
}

void pick_up_stack()
{
	while(is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
	}
}

void lay_out_stack()
{
	while (is_robot_carrying_items())
	{
		drop_item_from_robot();
		move_robot_forwards();
	}
}

void spread_beepers()
{
	find_beepers();
	pick_up_stack();
	lay_out_stack();
}