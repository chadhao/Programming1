/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  IMPORTANT: REMEMBER TO sync BEFORE YOU LEAVE THE EXAM ROOM
*
*******************************************************************************/

#include "test01q05.h"

//This function will make the robot pick up all beepers.
int pick_up_stack()
{
	int beeper_number = 0;
	while (is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
		beeper_number++;
	}
	return beeper_number;
}

//This function will move the robot towards the wall.
int move_to_wall()
{
	int steps = 0;
	while (!is_robot_facing_wall())
	{
		move_robot_forwards();
		steps++;
	}
	return steps;
}

//This function will make robot drop all beepers.
void drop_all_beepers()
{
	while (is_robot_carrying_items())
	{
		drop_item_from_robot();
	}
}

void move_beepers()
{
	int beeper_number;
	int steps;
	
	steps = move_to_wall();
	beeper_number = pick_up_stack();
	
	if (beeper_number == 5 && steps < 5)
	{
		turn_robot_left();
		turn_robot_left();
		turn_robot_left();
		move_to_wall();
		drop_all_beepers();
	}
	else if (beeper_number < 4 || steps > 4)
	{
		turn_robot_left();
		move_to_wall();
		drop_all_beepers();
	}
	else
	{
		turn_robot_left();
		turn_robot_left();
		move_to_wall();
		drop_all_beepers();
	}
}