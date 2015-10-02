#include "lab06ex06.h"

#include <stdlib.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
    p1u_setup();

    set_random_seed(time(0));

	enable_robot_debug_message();
	char* world[] = {
	
		"      ",
		" wwww ",
		" w  w ",
		" w  w ",
		" wwww ",
		"      "
	};    
    create_robot_world_from_string(world, 6, "lab06ex06", 1);
  
	int stack_size = rand() % 5;
	int wall = rand() % 4;
	int offset = rand() % 2;
	int x, y;
	switch(wall)
	{
	case 0:
			// North
		x = 2 + offset;
		y = 4;
		setup_floor(x, y);
		setup_beeper(x, y + 1);
		break;
	case 1:
			// East
		x = 4;
		y = 2 + offset;
		setup_floor(x, y);
		setup_beeper(x + 1, y);
		break;
	case 2:
			// South
		x = 2 + offset;
		y = 1;
		setup_floor(x, y);
		setup_beeper(x, y - 1);
		break;
		break;
	case 3:
			// West
		x = 1;
		y = 2 + offset;
		setup_floor(x, y);
		setup_beeper(x - 1, y);
		break;
		break;
	}
	create_robot_at(2, 2);
	
	escape_room();

    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
	P1U_ASSERT_TRUE("There should be a beeper at the robot's location", is_item_present(get_current_robot_x(), get_current_robot_y()));

	p1u_shutdown();	
    return (p1world_shutdown());
}