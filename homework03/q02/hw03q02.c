
/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw03q02.c
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

#include "hw03q02.h"

void move_beepers()
{
	turn_robot_left();
	move_robot_forwards();
	
	if (!is_item_on_ground_at_robot())
	{
		turn_robot_left();
		turn_robot_left();
		move_robot_forwards();
		turn_robot_left();
	}
	else
	{
		pick_up_item_with_robot();
		move_robot_forwards();
		
		if (!is_item_on_ground_at_robot())
		{
			turn_robot_left();
			turn_robot_left();
			move_robot_forwards();
			drop_item_from_robot();
			move_robot_forwards();
			turn_robot_left();
		}
		else
		{
			pick_up_item_with_robot();
			turn_robot_left();
			turn_robot_left();
			turn_robot_left();
			move_robot_forwards();
			move_robot_forwards();
			move_robot_forwards();
			move_robot_forwards();
			drop_item_from_robot();
			drop_item_from_robot();
		}
	}
}