/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q03.c
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

void draw_polygon(int number_of_sides)
{
    // The code in this function is incomplete!
    for (int i = 0; i < number_of_sides; ++i)
    {
        forward(25);
        turn(360 / number_of_sides);
    }
}

void next()
{
    pen_up();
    forward(65);
    pen_down();
}

int main(int argc, char *argv[])
{
    create_turtle_world();

    turn_on_debug_output();
    
    print_stub("Drawing a triangle");
    draw_polygon(3);
    next();
    
    print_stub("Drawing a square");
    draw_polygon(4);
    next();

    print_stub("Drawing a pentagon");
    draw_polygon(5);
    next();

    print_stub("Drawing a hexagon");
    draw_polygon(6);
    next();
    
    draw_polygon(7);
    next();
    
    draw_polygon(8);
    
    return (p1world_shutdown());
}