/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q06.c
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

void draw_five_point_star_at(int x_offset, int y_offset)
{
    pen_up();
    forward(x_offset);
    turn(90);
    forward(y_offset);
    turn(-90);
    turn(90);
    pen_down();
    
    pen_colour(NEXT);
    
    for (int i = 0; i < 5; ++i)
    {
        forward(80);
        turn(144);
    }
    
    pen_up();
    turn(-90);
    forward(-x_offset);
    turn(90);
    forward(-y_offset);
    turn(-90);
    pen_down();
}

int main(int argc, char *argv[])
{
    set_delay_time(1);
    create_turtle_world();
    
    draw_five_point_star_at(0, 0);
    draw_five_point_star_at(0, 100);
    draw_five_point_star_at(0, -100);
    draw_five_point_star_at(0, 200);
    draw_five_point_star_at(0, -200);

    draw_five_point_star_at(100, 0);
    draw_five_point_star_at(100, 100);
    draw_five_point_star_at(100, -100);
    draw_five_point_star_at(100, 200);
    draw_five_point_star_at(100, -200);

    draw_five_point_star_at(-100, 0);
    draw_five_point_star_at(-100, 100);
    draw_five_point_star_at(-100, -100);
    draw_five_point_star_at(-100, 200);
    draw_five_point_star_at(-100, -200);
    
    return (p1world_shutdown());
}
