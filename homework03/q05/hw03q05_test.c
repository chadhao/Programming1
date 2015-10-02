#include "hw03q05.h"

#include <time.h>
#include <stdlib.h>

#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
	char message[100];
	
    p1u_setup();
    
    srand(time(0));


	int width = 10;
	int height = 11;
	create_robot_world_with_dimensions(10, 11);

    setup_maze();
    
    for(int y = 1; y < height; y += 2)
    {
		int walls = 0;
		for(int x = 0; x < width; x++)
		{
			if(is_wall(x, y))
			{
				walls++;
			}
		}
		
		sprintf(message, "There should be %d walls on row Y = %d\n", width - 1, y);
		P1U_ASSERT_EQUAL(message, width - 1, walls);
    }
    
    create_robot();
   
    complete_maze();

	sprintf(message, "Robot should have moved to row Y = %d\n", height - 1);
 	P1U_ASSERT_EQUAL(message, height - 1, get_current_robot_y());
 	
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    p1u_shutdown();
    
    return (p1world_shutdown());
}