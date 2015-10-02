
/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw03q01.c
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

#include "hw03q01.h"

void turn_robot_around()
{
	for (int n = 0; n < 2; n++)
	{
		turn_robot_left();
	}
}

void turn_robot_right()
{
	for (int n = 0; n < 3; n++)
	{
		turn_robot_left();
	}
}

void pick_up_stack()
{
	while (is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
	}
}

void drop_all_items()
{
	while (is_robot_carrying_items())
	{
		drop_item_from_robot();
	}
}

void move_robot_forwards_n(int n)
{
	for (int i = 0; i < n; i++)
	{
		move_robot_forwards();
	}
}