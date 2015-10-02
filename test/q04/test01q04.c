/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  IMPORTANT: REMEMBER TO sync BEFORE YOU LEAVE THE EXAM ROOM
*
*******************************************************************************/

#include "test01q04.h"

void move_robot()
{
	while (!is_robot_facing_wall())
	{
		move_robot_forwards();
	}
	if (is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
		turn_robot_left();
		while (is_space_in_front_of_robot_clear())
		{
			move_robot_forwards();
		}
		drop_item_from_robot();
	}
	else
	{
		turn_robot_left();
		turn_robot_left();
		turn_robot_left();
		while (is_space_in_front_of_robot_clear())
		{
			move_robot_forwards();
		}
	}
}