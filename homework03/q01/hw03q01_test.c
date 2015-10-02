#include "hw03q01.h"

#include <unistd.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
    p1u_setup();
	enable_robot_debug_message();    

    set_random_seed(time(0));

    create_robot_world_with_dimensions(10, 10);
    for(int n = 0; n < 5; n++)
    {
    	setup_beeper(3, 4);
    }

    create_robot();
	turn_on_debug_output(1);    

	sleep(2);

	move_robot_forwards_n(3);

    P1U_ASSERT_EQUAL("Robot should be at X = 3", 3, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0, get_current_robot_y());

    turn_robot_left();
    
    	// Check that pick up stack does not kill robot when no items present
    pick_up_stack();
    
    move_robot_forwards_n(4);
    
    P1U_ASSERT_EQUAL("Robot should be at X = 3", 3, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 4", 4, get_current_robot_y());
    
    	// Pick up all beepers
    pick_up_stack();
    
    turn_robot_right();
    
    move_robot_forwards_n(1);
    
    drop_all_items();

		// Check that move_robot_forwards_n can cope with a 0 argument
	move_robot_forwards_n(0);
	
		// Check that all of the beepers have been moved
    P1U_ASSERT_EQUAL("There should be 5 beepers at (4, 4)", 5, get_count_of_beepers_at(4, 4));

    
    	// Check that drop_all_items() doesn't kill robot when none carried
    drop_all_items();

		// Final checks
    P1U_ASSERT_EQUAL("Robot should be at X = 4", 4, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 4", 4, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    p1u_shutdown();
    
    return (p1world_shutdown());
}