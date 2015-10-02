#include "lab06ex05.h"

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
    create_robot_world_with_dimensions(10, 10);
 
 	char message[128];
 
	int stack_size = rand() % 5;
    if(rand() % 2)
    {
    		// North
	    for(int n = 0; n < stack_size; n++)
	    {
	    	setup_beeper(1, 2);
	    }
		create_robot_at(1, 1);
		
		spread_beepers();
		
		for(int y = 2; y < 2 + stack_size; y++)
		{
			sprintf(message, "There should be a beeper at (1, %d)", y);
			P1U_ASSERT_TRUE(message, is_item_present(1, y));
		}
    	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
	}
	else
	{
    		// East
	    for(int n = 0; n < stack_size; n++)
	    {
	    	setup_beeper(2, 1);
	    }
		create_robot_at(1, 1);
		
		spread_beepers();
		
		for(int x = 2; x < 2 + stack_size; x++)
		{
			sprintf(message, "There should be a beeper at (%d, 1)", x);
			P1U_ASSERT_TRUE(message, is_item_present(x, 1));
		}
    	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

	}
	
    return (p1world_shutdown());
}