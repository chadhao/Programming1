#include "test01q04.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
    p1u_setup();

	printf("Test 1: No beeper\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world1[] = {
	
		"wwww w",
		"wwww w",
		"wwww w",
		"     w",
		"wwww w",
		"wwww w"
	};
	
    create_robot_world_from_string(world1, 6, "test01q01", 1);

	create_robot_at(0, 2);

	move_robot();

	p1world_shutdown();
	P1U_ASSERT_EQUAL("Robot should be at X = 4", 4, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0, get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing south", get_south(), get_current_robot_orientation());
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

 	
	printf("Test 2: Beeper present\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world2[] = {
	
		"wwww w",
		"wwww w",
		"wwww w",
		"    bw",
		"wwww w",
		"wwww w"
	};
	
    create_robot_world_from_string(world2, 6, "test01q01", 1);

	create_robot_at(0, 2);

	move_robot();

	p1world_shutdown();
	P1U_ASSERT_EQUAL("Robot should be at X = 4", 4, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 5", 5, get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing north", get_north(), get_current_robot_orientation());
	P1U_ASSERT_EQUAL("There should be one beeper at (4, 5)", 1, get_count_of_beepers_at(4, 5));
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
 	
 	p1u_shutdown();
	
    return 0;
}