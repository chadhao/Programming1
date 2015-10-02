#include "lab03ex03.h"

#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>

void fillWorldWithWalls()
{
    for(int x = 0; x < get_world_width(); x++)
    {
        for(int y = 0; y < get_world_height(); y++)
        {
            setup_wall(x, y);
        }
    }
}

void clearHorizontalCorridor(int x, int y, int length)
{
    int end = x + length;
    
    for(; x <= end; x++)
    {
        setup_floor(x, y);
    }
}

void clearVerticalCorridor(int x, int y, int length)
{
    int end = y + length;
    
    if(end > y)
    {
        for(; y <= end; y++)
        {
            setup_floor(x, y);
        }
    }
    else
    {
        for(; y >= end; y--)
        {
            setup_floor(x, y);
        }
    }
}

int createWorld()
{
    create_robot_world_with_name(10, 10, "Lab 03 Ex 01", 0);
    fillWorldWithWalls();
    
    int startX = 0;
    int startY = getRandom(0, 9);
    int x = startX;
    int y = startY;
    
    for(int n = 0; n < 3; n++)
    {
        // Clear horizontal corridor
        int length = getRandom(2, 3);
        clearHorizontalCorridor(x, y, length);
        x += length;
        
        // Clear vertical corridor
        do
        {
            length = getRandom(-9, 9);
        }
        while (length == 0 || y + length >= 10 || y + length < 0);
        
        clearVerticalCorridor(x, y, length);
        
        y += length;
    }
    
    // Clear to other side
    clearHorizontalCorridor(x, y, 9 - x);
    
    create_robot_with_direction(startX, startY, get_east());
    
    return y;
}

int main(int argc, char* argv[])
{
    p1u_setup();
    
    set_random_seed(time(0));

    int endY = createWorld();
    
    move_along_corridor();
    
    P1U_ASSERT_EQUAL("Robot should be at X = 9", 9, get_current_robot_x());
    
    char message[32];
    sprintf(message, "Robot should be at Y = %d", endY);
    P1U_ASSERT_EQUAL(message, endY, get_current_robot_y());
    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());
    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    p1u_shutdown();
    
    return (p1world_shutdown());
}