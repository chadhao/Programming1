/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab03ex03.c
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

void move_along_corridor()
{
	set_delay_time(1);
	while (is_space_in_front_of_robot_clear())
	{
		do
		{
			move_robot_forwards();
		} while(is_space_in_front_of_robot_clear());
		
		turn_robot_left();
		
		if (!is_space_in_front_of_robot_clear())
		{
			turn_robot_left();
			turn_robot_left();
			if (!is_space_in_front_of_robot_clear())
			{
				turn_robot_left();
			}
		}
	}
}