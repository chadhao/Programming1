/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q05.c
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

void draw_windmill(int scale_factor)
{
    pen_colour(NEXT);
    
    for (int i = 0; i < 4; ++i)
    {
        forward(45 * scale_factor);
        turn(90);
        forward(45 * scale_factor);
        turn(135);
        forward(64 * scale_factor);
    
        turn(45);
    }
}

int main(int argc, char *argv[])
{
    create_turtle_world();
    
    draw_windmill(1);
    draw_windmill(2);
    draw_windmill(3);
    draw_windmill(4);
    draw_windmill(5);
    
    return (p1world_shutdown());
}
