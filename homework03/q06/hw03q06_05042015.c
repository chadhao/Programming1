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

void complete_maze()
{
	int route[11][17];
	
	for (int a = 0; a < 11; a++)
	{
		for (int b = 0; b < 17; b++)
		{
			route[a][b] = 10;
		}
	}
	
	//Value 11 stands for starting point.
	route[get_current_robot_x()][get_current_robot_y()] = 11;
	
	while (!is_item_on_ground_at_robot())
	{
		//Walking strategies.
		//Record footprint while walking through each grid.
		//Value 9 stands for the grid has already been visited.
		//To be modified.
		while (is_space_in_front_of_robot_clear())
		{
			move_robot_forwards();
			if (route[get_current_robot_x()][get_current_robot_y()] == 11)
			{
				turn_robot_left();
				turn_robot_left();
			}
			else if (route[get_current_robot_x()][get_current_robot_y()] == 10)
			{
				route[get_current_robot_x()][get_current_robot_y()] = 9;
			}
		}
		
		//Judging direction at T road.
		//Value stands for:
		//0:North, 1:East, 2:South, 3:West
		turn_robot_left();
		if (is_space_in_front_of_robot_clear())
		{
			turn_robot_left();
			turn_robot_left();
			if (is_space_in_front_of_robot_clear())
			{
				route[get_current_robot_x()][get_current_robot_y()] = get_current_robot_orientation();
			}
			turn_robot_left();
		}
		else
		{
			turn_robot_left();
			turn_robot_left();
			turn_robot_left();
		}
		//Here, robot must be facing wall at a T road, knowing its direction.
		
		printf("\nx%d,y%d:%d\n", get_current_robot_x(), get_current_robot_y(), route[get_current_robot_x()][get_current_robot_y()]);
		
		//Changing direction when facing wall.
		while (is_robot_facing_wall())
		{
			turn_robot_left();
			if (is_robot_facing_wall())
			{
				turn_robot_left();
				turn_robot_left();
				if (is_robot_facing_wall())
				{
					turn_robot_left();
					turn_robot_left();
					turn_robot_left();
				}
			}
		}
	}
}