#include "hw03q06.h"

#include <stdlib.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>

int width = 11;
int height = 17;
int maze_y = 2;
	// must be height - 4
int maze_height = 13;


int get_random(int low, int high)
{
	return low + (rand() % (1 + high - low));
}


int is_maze_wall(int mx, int my)
{
	int y = my + maze_y;
	return mx < 0 || mx >= width || y < maze_y || y >= height - 2 || is_wall(mx, y);
}


int is_removable_wall(int mx, int my)
{
	int neighbours = 0;
	if(is_maze_wall(mx, my - 1))
	{
		neighbours++;
	}
	if(is_maze_wall(mx, my + 1))
	{
		neighbours++;
	}
	if(is_maze_wall(mx - 1, my))
	{
		neighbours++;
	}
	if(is_maze_wall(mx + 1, my))
	{
		neighbours++;
	}
		// If it is a wall with three neighbours then we can
		// tunnel it away
	int y = my + maze_y;	
	return mx >= 0 && mx < width && y > 0 && my < maze_height && is_wall(mx, y) && neighbours == 3;
}

int create_maze()
{
	
	for(int y = 1; y < height - 1; y++)
	{
		for(int x = 0; x < width; x++)
		{
			setup_wall(x, y);
		}
	}
	
		// Entrance to maze
	setup_floor(5, 1);
	setup_floor(5, 2);
	
	int done = 0;
	while(!done)
	{
		int mx = get_random(0, width - 1);
		int my = get_random(0, maze_height - 1);
		if(is_removable_wall(mx, my))
		{
			setup_floor(mx, my + maze_y);
		}
		done = 1;
		for(my = 0; my < maze_height && done; my++)
		{
			for(mx = 0; mx < width && done; mx++)
			{
				done &= !is_removable_wall(mx, my);
			}
		}
	}
		// Exit from maze
	setup_floor(5, height - 2);
	setup_floor(5, height - 3);
	setup_beeper(5, height - 1);	

}

int main(int argc, char* argv[])
{
    p1u_setup();

	srand(time(0));
	
	create_robot_world_with_dimensions(width, height);
	
	create_maze();
	
	create_robot_with_direction(5, 0, get_north());
    
    complete_maze();
    
    char message[100];
    sprintf(message, "Robot should be at Y = %d", height - 1);
    P1U_ASSERT_EQUAL(message, height - 1, get_current_robot_y());
    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    p1u_shutdown();
    
    return (p1world_shutdown());
}