
#include "lab03ex05.h"

// Clean up one corridor. 
void clean_up_corridor()
{
	while (!is_robot_facing_wall())
	{
		if (is_item_on_ground_at_robot())
		{
			pick_up_item_with_robot();
		}
		move_robot_forwards();
	}
	if (is_item_on_ground_at_robot())
	{
		pick_up_item_with_robot();
	}
}

// Let robot turn right.
void turn_robot_right()
{
	for (int n = 0; n < 3; n++)
	{
		turn_robot_left();
	}
}

// Clean up the hole map.
void clean_up_world()
{
	// Judge which corridor to clean and clean it, then setup for next one.
	for (int n = 1; n <= 6; n++)
	{
		if (n == 6)
		{
			clean_up_corridor();
			turn_robot_left();
		}
		else if (n % 2 == 1)
		{
			clean_up_corridor();
			turn_robot_left();
			move_robot_forwards();
			turn_robot_left();
		}
		else
		{
			clean_up_corridor();
			turn_robot_right();
			move_robot_forwards();
			turn_robot_right();
		}
	}
	
	// Bring robot back to start position.
	while (!is_robot_facing_wall())
	{
		move_robot_forwards();
	}
	turn_robot_left();
}