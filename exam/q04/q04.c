
#include <p1student.h>
#include "q04.h"

void mark_corners()
{
	while(!is_robot_facing_wall())
	{
		move_robot_forwards();
		if (is_robot_facing_wall() && is_robot_carrying_items())
		{
			drop_item_from_robot();
			turn_robot_left();
		}
		if (!is_robot_carrying_items())
		{	
			break;
		}
	}
}