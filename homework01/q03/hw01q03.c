/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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
*******************************************************************************/


#include "p1student.h"

void draw_rectangle_red()
{
    pen_colour(RED);
    forward(150);
    turn(90);
    forward(50);
    turn(90);
    forward(150);
    turn(90);
    forward(50);
    turn(90);
}

void draw_rectangle_blue()
{
    pen_colour(BLUE);
    forward(150);
    turn(-90);
    forward(50);
    turn(-90);
    forward(150);
    turn(-90);
    forward(50);
    turn(-90);
}

void draw_square()
{
    pen_colour(BLACK);
    turn(90);
    forward(315);
    turn(90);
    forward(315);
    turn(90);
    forward(315);
    turn(90);
    forward(315);
}

int main(int argc, char *argv[])
{
    create_turtle_world();
    turn(-45);
    
    draw_rectangle_red();
    
    turn(-90);
    
    draw_rectangle_blue();
    
    pen_up();
    turn(225);
    forward(71);
    pen_down();
    turn(45);
    
    draw_rectangle_red();
    
    turn(-90);
    
    draw_rectangle_blue();
    
    pen_up();
    turn(45);
    forward(125);
    turn(90);
    forward(150);
    pen_down();
    
    draw_square();
    
    hide_turtle();
    
    return (p1world_shutdown());
}
